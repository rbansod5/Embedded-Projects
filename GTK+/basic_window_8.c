#include <gtk/gtk.h>

static void on_open_button_clicked(GtkWidget *widget, gpointer window) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Open File",
                                                  GTK_WINDOW(window),
                                                  GTK_FILE_CHOOSER_ACTION_OPEN,
                                                  "_Cancel", GTK_RESPONSE_CANCEL,
                                                  "_Open", GTK_RESPONSE_ACCEPT,
                                                  NULL);

    gint result = gtk_dialog_run(GTK_DIALOG(dialog));
    if (result == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        char *filename = gtk_file_chooser_get_filename(chooser);
        g_print("File selected: %s\n", filename);
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "File Chooser Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *button_open = gtk_button_new_with_label("Open File");

    g_signal_connect(button_open, "clicked", G_CALLBACK(on_open_button_clicked), window);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), button_open, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), box);

    // Connect window destroy signal
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

