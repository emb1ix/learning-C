#include <stdio.h>
#include <gtk/gtk.h>
#include "window.h"
#include "calculator.h"


int main(void) {
    GtkWidget *window = init_window();

    // Creates the grid
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Sets spacing for the grid
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);

    render_buttons(grid); 

     // Runs the GTK window
    gtk_widget_show_all(window);
    gtk_main();


    return 0;
    }
