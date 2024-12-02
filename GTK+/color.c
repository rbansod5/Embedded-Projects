#include <gtk/gtk.h>

static gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    int width = gtk_widget_get_width(widget);
    int height = gtk_widget_get_height(widget);

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            cairo_set_source_rgb(cr, i / 255.0, j / 255.0, (i + j) / 510.0);
            cairo_rectangle(cr, (i % 16) * (width / 16), (j % 16) * (height / 16), width / 16, height / 16);
            cairo_fill(cr);
        }
    }
    return FALSE;
}

int main(int argc, char *argv[]) {
    gtk_init();

    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "All Colors");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 800);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_window_destroy), NULL);

    GtkWidget *drawing_area = gtk_drawing_area_new();
    gtk_window_set_child(GTK_WINDOW(window), drawing_area);
    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL);

    gtk_widget_set_visible(window, TRUE);
    gtk_main();

    return 0;
}

