#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    // Step 1: Initialize GTK
    gtk_init(&argc, &argv);

    // Step 2: Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Step 3: Set window properties
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Step 4: Connect the window's "destroy" event to gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Step 5: Show the window
    gtk_widget_show(window);

    // Step 6: Enter the main GTK loop
    gtk_main();

    return 0;
}

