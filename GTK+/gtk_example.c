#include <gtk/gtk.h>

// Callback function for button click
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Hello, GTK!\n");
}

// Main application function
int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Create a new button and connect it to the callback function
    button = gtk_button_new_with_label("Click Me");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Add the button to the window
    gtk_container_add(GTK_CONTAINER(window), button);

    // Connect the window's "destroy" signal to GTK's main quit function
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets in the window
    gtk_widget_show_all(window);

    // Enter the GTK main loop
    gtk_main();

    return 0;
}

