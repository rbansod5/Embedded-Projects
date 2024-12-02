#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>

GtkWidget *entry;

void on_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *button_text = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar *current_text = gtk_entry_get_text(GTK_ENTRY(entry));
    gchar *new_text;

    if (strcmp(button_text, "C") == 0) {
        gtk_entry_set_text(GTK_ENTRY(entry), "");
    } else if (strcmp(button_text, "=") == 0) {
        gchar *expression = strdup(current_text);
        int result = 0;

        // Very basic evaluation (works with simple expressions only)
        if (sscanf(expression, "%d+%d", &result, &result) == 2)
            sprintf(expression, "%d", result);
        else if (sscanf(expression, "%d-%d", &result, &result) == 2)
            sprintf(expression, "%d", result);
        else if (sscanf(expression, "%d*%d", &result, &result) == 2)
            sprintf(expression, "%d", result);
        else if (sscanf(expression, "%d/%d", &result, &result) == 2)
            sprintf(expression, "%d", result);
        
        gtk_entry_set_text(GTK_ENTRY(entry), expression);
        free(expression);
    } else {
        new_text = g_strconcat(current_text, button_text, NULL);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
        g_free(new_text);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 800);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    entry = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(entry), 1);  // Right-align text
    gtk_box_pack_start(GTK_BOX(vbox), entry, FALSE, FALSE, 0);

    const char *buttons[] = {
        "7", "8", "9", "/",
        "4", "5", "6", "*",
        "1", "2", "3", "-",
        "0", "C", "=", "+",
    };

    GtkWidget *grid = gtk_grid_new();
    gtk_box_pack_start(GTK_BOX(vbox), grid, TRUE, TRUE, 0);

    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            GtkWidget *button = gtk_button_new_with_label(buttons[i * 4 + j]);
            gtk_grid_attach(GTK_GRID(grid), button, j, i, 1, 1);
            g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
        }
    }

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

