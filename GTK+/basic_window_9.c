#include <gtk/gtk.h>

static void on_copy_button_clicked(GtkWidget *widget, gpointer data) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_text(clipboard, "Hello, Clipboard!", -1);
}

static void on_paste_button_clicked(GtkWidget *widget, gpointer data) {
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gchar *text = gtk_clipboard_wait_for_text(clipboard);
    if (text) {
        g_print("Pasted text: %s\n", text);
        g_free(text);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Clipboard Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    GtkWidget *button_copy = gtk_button_new_with_label("Copy");
    GtkWidget *button_paste = gtk_button_new_with_label("Paste");

    g_signal_connect(button_copy, "clicked", G_CALLBACK(on_copy_button_clicked), NULL);
    g_signal_connect(button_paste, "clicked", G_CALLBACK(on_paste_button_clicked), NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), button_copy, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_paste, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), box);

    // Connect window destroy signal
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

