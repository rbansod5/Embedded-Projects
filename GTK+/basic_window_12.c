#include <gtk/gtk.h>
#include <cairo.h>

static gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
    cairo_set_source_rgb(cr, 0.2, 0.5, 0.8);  // Set color
    cairo_paint(cr);  // Fill the window with the color
    
    cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  // Red color
    cairo_arc(cr, 100, 100, 50, 0, 2 * G_PI);  // Draw circle
    cairo_fill(cr);

    return FALSE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Cairo Drawing Example");
    gtk_widget_set_size_request(window, 400, 400);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(window, "draw", G_CALLBACK(on_draw), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

