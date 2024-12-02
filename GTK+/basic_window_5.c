#include <gtk/gtk.h>

static void on_secondary_window(GtkWidget *widget, gpointer window) {
    GtkWidget *secondary_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(secondary_window), "Secondary Window");
    gtk_window_set_default_size(GTK_WINDOW(secondary_window), 300, 200);
    
    GtkWidget *label = gtk_label_new("This is a secondary window!");
    gtk_container_add(GTK_CONTAINER(secondary_window), label);

    // Connect the window destroy signal
    g_signal_connect(secondary_window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);

    gtk_widget_show_all(secondary_window);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Main Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *button = gtk_button_new_with_label("Open Secondary Window");
    g_signal_connect(button, "clicked", G_CALLBACK(on_secondary_window), window);
    gtk_container_add(GTK_CONTAINER(window), button);

    // Connect window destroy signal
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

