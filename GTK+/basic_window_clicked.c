#include <gtk/gtk.h>

// This is the callback function that will be called when the button is clicked
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Hello, GTK+!\n");  // Print a message to the console
    gtk_main_quit();  // Close the GTK+ main loop (this closes the window)
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);  // Initialize GTK+

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Hello GTK+");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Create a new button
    GtkWidget *button = gtk_button_new_with_label("Click Me!");

    // Connect the button's "clicked" signal to the callback function
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Add the button to the window
    gtk_container_add(GTK_CONTAINER(window), button);

    // Connect the window's "destroy" signal to the GTK+ main loop quit function
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets (the window and the button)
    gtk_widget_show_all(window);

    // Enter the GTK+ main loop (the application will run until the user closes the window)
    gtk_main();

    return 0;
}

