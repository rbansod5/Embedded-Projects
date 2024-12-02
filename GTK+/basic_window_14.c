#include <gtk/gtk.h>

// Function to close a tab
static void on_close_tab(GtkWidget *button, GtkWidget *notebook) {
    GtkWidget *current_label = gtk_widget_get_parent(button); // Get the tab label (the parent of the button)
    GtkWidget *page = gtk_notebook_get_nth_page(GTK_NOTEBOOK(notebook), gtk_notebook_page_num(GTK_NOTEBOOK(notebook), current_label));

    // Remove the tab from the notebook
    gtk_notebook_remove_page(GTK_NOTEBOOK(notebook), gtk_notebook_page_num(GTK_NOTEBOOK(notebook), current_label));
}

// Function to rename the tab when the user presses Enter
static void on_rename_activate(GtkWidget *entry, gpointer data) {
    const gchar *new_name = gtk_entry_get_text(GTK_ENTRY(entry));
    GtkWidget *label = GTK_WIDGET(data);
    
    // Update the tab label with the new name
    gtk_label_set_text(GTK_LABEL(label), new_name);
    
    // Remove the entry widget after renaming
    gtk_widget_destroy(entry);
}

// Function to create a new tab in the GtkNotebook
static void open_new_tab(GtkWidget *notebook) {
    // Create a new label to represent the new tab
    GtkWidget *label = gtk_label_new("New Tab");

    // Create a new box container for the new tab
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(box), gtk_label_new("This is a new tab"));

    // Create a close button for the tab
    GtkWidget *close_button = gtk_button_new_with_label("X");
    g_signal_connect(close_button, "clicked", G_CALLBACK(on_close_tab), notebook);

    // Add the close button to the tab label
    GtkWidget *tab_label = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(tab_label), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(tab_label), close_button, FALSE, FALSE, 0);
    
    // Add the new page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box, tab_label);
    gtk_widget_show_all(notebook);  // Show the new tab
}

// Callback to rename a tab (triggered by right-click)
static gboolean on_tab_rename(GtkWidget *widget, GdkEventButton *event, GtkNotebook *notebook) {
    if (event->type == GDK_BUTTON_PRESS && event->button == 3) {  // Right-click
        GtkWidget *current_label = gtk_notebook_get_tab_label(notebook, widget);
        const gchar *current_name = gtk_label_get_text(GTK_LABEL(current_label));

        // Create a text entry to allow renaming
        GtkWidget *entry = gtk_entry_new();
        gtk_entry_set_text(GTK_ENTRY(entry), current_name);
        gtk_widget_show(entry);

        // Callback to handle the rename action when the user presses Enter
        g_signal_connect(entry, "activate", G_CALLBACK(on_rename_activate), (gpointer)current_label);

        // Place the entry widget in the current tab label
        gtk_container_add(GTK_CONTAINER(current_label), entry);
        gtk_widget_show_all(current_label);

        return TRUE;
    }
    return FALSE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Renaming and Closing Tabs in GTK+");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a notebook (tabbed interface)
    GtkWidget *notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Create a menu bar
    GtkWidget *menu_bar = gtk_menu_bar_new();
    GtkWidget *file_menu_item = gtk_menu_item_new_with_label("File");
    GtkWidget *file_menu = gtk_menu_new();
    GtkWidget *new_tab_item = gtk_menu_item_new_with_label("New Tab");

    // Connect to the menu item to open new tabs
    g_signal_connect(new_tab_item, "activate", G_CALLBACK(open_new_tab), notebook);

    // Attach the menu items to the menu
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), new_tab_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);

    // Add the menu to the menu bar
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu_item);

    // Create a box to hold the menu bar and notebook
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(vbox), menu_bar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), notebook, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Connect the tab renaming event
    g_signal_connect(notebook, "button-press-event", G_CALLBACK(on_tab_rename), notebook);

    // Display everything
    gtk_widget_show_all(window);

    // Run the GTK main loop
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();

    return 0;
}

