#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *button, gpointer entry) {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    g_print("You entered: %s\n", text);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GtkBox Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Create a vertical box container
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5); // 5px spacing between widgets
    gtk_container_add(GTK_CONTAINER(window), box);

    // Create a label and add it to the box
    GtkWidget *label = gtk_label_new("Enter your name:");
    gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);

    // Create a text entry widget and add it to the box
    GtkWidget *entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);

    // Create a button and add it to the box
    GtkWidget *button = gtk_button_new_with_label("Submit");
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);

    // Connect the button click signal to the callback function
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry);

    // Connect the window destroy signal to gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Show all widgets
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

