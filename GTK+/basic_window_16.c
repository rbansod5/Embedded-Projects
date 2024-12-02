#include <gtk/gtk.h>

// Callback functions for menu actions
static void on_new_activate(GtkWidget *widget, gpointer data) {
    g_print("New File selected\n");
}

static void on_open_activate(GtkWidget *widget, gpointer data) {
    g_print("Open File selected\n");
}

static void on_save_activate(GtkWidget *widget, gpointer data) {
    g_print("Save File selected\n");
}

static void on_exit_activate(GtkWidget *widget, gpointer data) {
    gtk_main_quit();  // Exit the application
}

static void on_ping_activate(GtkWidget *widget, gpointer data) {
    g_print("Ping selected\n");
}

static void on_traceroute_activate(GtkWidget *widget, gpointer data) {
    g_print("Traceroute selected\n");
}

static void on_disk_usage_activate(GtkWidget *widget, gpointer data) {
    g_print("Disk Usage selected\n");
}

static void on_system_monitor_activate(GtkWidget *widget, gpointer data) {
    g_print("System Monitor selected\n");
}

static void on_preferences_activate(GtkWidget *widget, gpointer data) {
    g_print("Preferences selected\n");
}

static void on_network_settings_activate(GtkWidget *widget, gpointer data) {
    g_print("Network Settings selected\n");
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *menu_bar;
    
    // File Menu
    GtkWidget *file_menu_item, *file_menu;
    GtkWidget *new_item, *open_item, *save_item, *exit_item;

    // Tools Menu
    GtkWidget *tools_menu_item, *tools_menu;
    GtkWidget *network_tools_menu_item, *network_tools_menu;
    GtkWidget *ping_item, *traceroute_item;
    GtkWidget *system_tools_menu_item, *system_tools_menu;
    GtkWidget *disk_usage_item, *system_monitor_item;

    // Settings Menu
    GtkWidget *settings_menu_item, *settings_menu;
    GtkWidget *preferences_item, *network_settings_item;
    
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "My Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    
    // Create a menu bar
    menu_bar = gtk_menu_bar_new();

    // --- File Menu ---
    file_menu_item = gtk_menu_item_new_with_label("File");
    file_menu = gtk_menu_new();
    new_item = gtk_menu_item_new_with_label("New");
    open_item = gtk_menu_item_new_with_label("Open");
    save_item = gtk_menu_item_new_with_label("Save");
    exit_item = gtk_menu_item_new_with_label("Exit");

    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), new_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), open_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), save_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), exit_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_menu_item), file_menu);

    // --- Tools Menu ---
    tools_menu_item = gtk_menu_item_new_with_label("Tools");
    tools_menu = gtk_menu_new();
    
    // Network Tools Submenu
    network_tools_menu_item = gtk_menu_item_new_with_label("Network Tools");
    network_tools_menu = gtk_menu_new();
    ping_item = gtk_menu_item_new_with_label("Ping");
    traceroute_item = gtk_menu_item_new_with_label("Traceroute");
    
    gtk_menu_shell_append(GTK_MENU_SHELL(network_tools_menu), ping_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(network_tools_menu), traceroute_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(network_tools_menu_item), network_tools_menu);

    // System Tools Submenu
    system_tools_menu_item = gtk_menu_item_new_with_label("System Tools");
    system_tools_menu = gtk_menu_new();
    disk_usage_item = gtk_menu_item_new_with_label("Disk Usage");
    system_monitor_item = gtk_menu_item_new_with_label("System Monitor");
    
    gtk_menu_shell_append(GTK_MENU_SHELL(system_tools_menu), disk_usage_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(system_tools_menu), system_monitor_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(system_tools_menu_item), system_tools_menu);

    // Add submenus to Tools menu
    gtk_menu_shell_append(GTK_MENU_SHELL(tools_menu), network_tools_menu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(tools_menu), system_tools_menu_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(tools_menu_item), tools_menu);

    // --- Settings Menu ---
    settings_menu_item = gtk_menu_item_new_with_label("Settings");
    settings_menu = gtk_menu_new();
    preferences_item = gtk_menu_item_new_with_label("Preferences");
    network_settings_item = gtk_menu_item_new_with_label("Network Settings");
    
    gtk_menu_shell_append(GTK_MENU_SHELL(settings_menu), preferences_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(settings_menu), network_settings_item);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(settings_menu_item), settings_menu);

    // Add menu items to the menu bar
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_menu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), tools_menu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), settings_menu_item);

    // Connect menu items to callback functions
    g_signal_connect(new_item, "activate", G_CALLBACK(on_new_activate), NULL);
    g_signal_connect(open_item, "activate", G_CALLBACK(on_open_activate), NULL);
    g_signal_connect(save_item, "activate", G_CALLBACK(on_save_activate), NULL);
    g_signal_connect(exit_item, "activate", G_CALLBACK(on_exit_activate), NULL);
    
    g_signal_connect(ping_item, "activate", G_CALLBACK(on_ping_activate), NULL);
    g_signal_connect(traceroute_item, "activate", G_CALLBACK(on_traceroute_activate), NULL);
    
    g_signal_connect(disk_usage_item, "activate", G_CALLBACK(on_disk_usage_activate), NULL);
    g_signal_connect(system_monitor_item, "activate", G_CALLBACK(on_system_monitor_activate), NULL);
    
    g_signal_connect(preferences_item, "activate", G_CALLBACK(on_preferences_activate), NULL);
    g_signal_connect(network_settings_item, "activate", G_CALLBACK(on_network_settings_activate), NULL);

    // Create a box to hold the menu bar and the main content
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_box_pack_start(GTK_BOX(vbox), menu_bar, FALSE, FALSE, 0);

    // Add the vbox to the window
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Show all widgets
    gtk_widget_show_all(window);

    // Connect the "destroy" signal to exit the GTK main loop
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Run the GTK main loop
    gtk_main();

    return 0;
}

