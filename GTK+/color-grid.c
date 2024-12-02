#include <gtk/gtk.h>

static gboolean on_draw(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer data) {
    double colors[5][3] = {
        {1.0, 0.0, 0.0}, // Red
        {0.0, 1.0, 0.0}, // Green
        {0.0, 0.0, 1.0}, // Blue
        {1.0, 1.0, 0.0}, // Yellow
        {1.0, 0.0, 1.0}  // Magenta
    };

    int rect_width = width / 5;
    int rect_height = height;

    for (int i = 0; i < 5; i++) {
        cairo_set_source_rgb(cr, colors[i][0], colors[i][1], colors[i][2]);
        cairo_rectangle(cr, i * rect_width, 0, rect_width, rect_height);
        cairo_fill(cr);
    }

    return TRUE;
}

int main(int argc, char **argv) {
    gtk_init();

    GtkWidget *window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Color Grid");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 100);

    GtkWidget *drawing_area = gtk_drawing_area_new();
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), on_draw, NULL, NULL);
    gtk_window_set_child(GTK_WINDOW(window), drawing_area);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_window_destroy), NULL);

    gtk_widget_show(window);
    gtk_main();

    return 0;
}

