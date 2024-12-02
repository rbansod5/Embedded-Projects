#include <gtk/gtk.h>

typedef struct {
    GtkWidget parent_instance;
    gint counter;
} MyCustomWidget;

typedef struct {
    GtkWidgetClass parent_class;
} MyCustomWidgetClass;

G_DEFINE_TYPE(MyCustomWidget, my_custom_widget, GTK_TYPE_WIDGET)

static void my_custom_widget_class_init(MyCustomWidgetClass *klass) {
    // Initialize any class-level properties or signals
}

static void my_custom_widget_init(MyCustomWidget *widget) {
    widget->counter = 0;  // Set default value
}

GtkWidget *my_custom_widget_new(void) {
    return g_object_new(MY_CUSTOM_WIDGET_TYPE, NULL);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *widget = my_custom_widget_new();
    gtk_container_add(GTK_CONTAINER(window), widget);

    gtk_widget_show_all(window);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_main();

    return 0;
}

