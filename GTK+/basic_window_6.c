#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GtkGrid Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create widgets
    GtkWidget *label_name = gtk_label_new("Name:");
    GtkWidget *entry_name = gtk_entry_new();
    GtkWidget *label_age = gtk_label_new("Age:");
    GtkWidget *entry_age = gtk_entry_new();
    GtkWidget *submit_button = gtk_button_new_with_label("Submit");

    // Attach widgets to the grid
    gtk_grid_attach(GTK_GRID(grid), label_name, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_name, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), label_age, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_age, 1, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), submit_button, 0, 2, 3, 1);

    // Connect window destroy signal
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

