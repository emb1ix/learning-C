#include <stdio.h>
#include <gtk/gtk.h>

int main(void) {
    // Initializes the GTK window
    gtk_init(NULL, NULL);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Creates the GTK window

    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700); // Sets the default size of the GTK window
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // Closes the GTK window when the X button is clicked


    // Creates the grid
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Sets spacing for the grid
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);


    // Adds all the numerical buttons (with the exception of 0) to the grid
    int amount_of_runs = 0;
    for (int y = 1; y < 4; y++) {
        for (int x = 0; x < 3; x++) {
        char label[8];

        int y_backwards = 4-y; // Draws them "upside down", so that they are drawn from the bottom up
        amount_of_runs += 1;
        sprintf(label, "%d", (amount_of_runs)); // Gives them their name
        GtkWidget *button = gtk_button_new_with_label(label);
        gtk_widget_set_size_request(button, 180, 100);  // Width, Height in pixels
        gtk_grid_attach(GTK_GRID(grid), button, x, y_backwards, 1, 1);
    }
    }
    
    // Adds the 0 button to the grid
    GtkWidget *button = gtk_button_new_with_label("0");
    gtk_widget_set_size_request(button, 180, 100);  // Width, Height in pixels
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 3, 1);



    
    // Creates the non-numerical buttons
    const char list_of_non_numerical_buttons[] = {'+', '-', '*'};
    const int list_of_x_and_y_on_non_numerical_buttons[] = {8};

    int x_non_numerical_buttons = 0;
    int y_non_numerical_buttons = 0;
    for (int i = 0; i < 3; i++) {
        char label[2];
        sprintf(label, "%c", list_of_non_numerical_buttons[i]);
        GtkWidget *button = gtk_button_new_with_label(label);
        gtk_widget_set_size_request(button, 180, 100);  // Width, Height in pixels
        gtk_grid_attach(GTK_GRID(grid), button, x_non_numerical_buttons, y_non_numerical_buttons, 1, 1);
        x_non_numerical_buttons += 1;
    }

    // Runs the GTK window
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
    }