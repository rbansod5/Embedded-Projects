#include <gtk/gtk.h>

// Function to create a new tab in the GtkNotebook
static void open_new_tab(GtkWidget *notebook) {
    // Create a new label to represent the new tab
    GtkWidget *label = gtk_label_new("New Tab");

    // Create a new box container for the new tab
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(box), gtk_label_new("This is a new tab"));

    // Add the new page to the notebook
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), box, label);
    gtk_widget_show_all(notebook);  // Show the new tab
}

// Callback function when hovering over the menu item to create a new tab
static void on_menu_item_hover(GtkWidget *widget, GtkNotebook *notebook) {
    open_new_tab(notebook);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "GTK+ Menu Hover New Tab");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a notebook (tabbed interface)
    GtkWidget *notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    // Create a simple "File" menu with a "New Tab" item
    GtkWidget *menu_bar = gtk_menu_bar_new();
    GtkWidget *file_menu_item = gtk_menu_item_new_with_label("File");
    GtkWidget *file_menu = gtk_menu_new();
    GtkWidget *new_tab_item = gtk_menu_item_new_with_label("New Tab");

    // Connect the hover event to the new tab function
    g_signal_connect(new_tab_item, "enter-notify-event", G_CALLBACK(on_menu_item_hover), notebook);

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

    // Display everything
    gtk_widget_show_all(window);

    // Run the GTK main loop
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();

    return 0;
}

