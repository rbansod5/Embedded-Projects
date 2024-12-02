#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *button, gpointer entry) {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    g_print("You entered: %s\n", text);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GtkGrid Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Create a grid container
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create a label and add it to the grid
    GtkWidget *label = gtk_label_new("Enter your name:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);  // Attach to grid at (row 0, column 0)

    // Create a text entry widget and add it to the grid
    GtkWidget *entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 1, 1);  // Attach to grid at (row 0, column 1)

    // Create a button and add it to the grid
    GtkWidget *button = gtk_button_new_with_label("Submit");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);  // Span across 2 columns in row 1

    // Connect the button click signal to the callback function
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);

    // Connect the window destroy signal to gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

