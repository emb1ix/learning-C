#include "window.h"
#include <gtk/gtk.h>

GtkWidget* init_window(void) {
    // Initializes the GTK window
    gtk_init(NULL, NULL);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Creates the GTK window

    gtk_window_set_title(GTK_WINDOW(window), "Calculator");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // Closes the GTK window when the X button is clicked
    return window;
    
} 

