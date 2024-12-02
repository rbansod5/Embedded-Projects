#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *button, gpointer data) {
    g_print("Button clicked!\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GtkFixed Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a fixed container
    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Create a label and position it at (50, 50)
    GtkWidget *label = gtk_label_new("Fixed Position Label");
    gtk_fixed_put(GTK_FIXED(fixed), label, 50, 50);

    // Create a button and position it at (50, 100)
    GtkWidget *button = gtk_button_new_with_label("Click Me");
    gtk_fixed_put(GTK_FIXED(fixed), button, 50, 100);

    // Connect the button click signal to the callback function
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Connect the window destroy signal to gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

