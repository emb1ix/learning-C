#include <stdio.h>
#include <gtk/gtk.h>

int main(void) {
    // Initializes the GTK window
    gtk_init(NULL, NULL);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Creates the GTK window
    gtk_window_set_title(GTK_WINDOW(window), "Calculator"); // Sets the title of the GTK window
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700); // Sets the default size of the GTK window
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL); // Closes the GTK window when the X button is clicked


    // Creates the grid
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Sets spacing for the grid
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);


    // Creates an array to store the numerical buttons
    GtkWidget *number_buttons[10];
    GtkWidget *non_numerical_buttons[6];

    // Adds all the numerical buttons (with the exception of 0) to the grid
    int amount_of_y_rows = 7;
    int amount_of_runs = 0;
    for (int y = 2; y < 5; y++) {
        for (int x = 0; x < 3; x++) {
        char label[8];

        int y_backwards = amount_of_y_rows - y; // Draws them "upside down", so that they are drawn from the bottom up.
        amount_of_runs++;
        sprintf(label, "%d", (amount_of_runs)); // Gives them their text label
        GtkWidget *button = gtk_button_new_with_label(label);
        gtk_widget_set_size_request(button, 180, 100);  // Width, Height in pixels
        gtk_grid_attach(GTK_GRID(grid), button, x, y_backwards, 1, 1);

        number_buttons[amount_of_runs] = button; // Adds the buttons to the array of numerical buttons.
    }
    }

    // Adds the 0 button to the grid
    GtkWidget *button = gtk_button_new_with_label("0");
    gtk_widget_set_size_request(button, 180, 100);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 3, 1);
    number_buttons[0] = button; // Adds the 0 button to the array of numerical buttons

    // Creates a textfield and adds it to the grid
    GtkWidget *textfield = gtk_entry_new();
    gtk_widget_set_size_request(textfield, 180, 175);
    gtk_grid_attach(GTK_GRID(grid), textfield, 0, 0, 3, 1);

    // Creates the non-numerical buttons

    const char list_of_non_numerical_buttons[] = {'C', '=', '*', '+', '-', '/'};
    const int list_of_x_and_y_on_non_numerical_buttons[] = {8};
    int x_non_numerical_buttons = 0; // Where on the grid the buttons should be placed.
    int y_non_numerical_buttons = 1;
    for (int i = 0; i < 6; i++) {
        if (i == 3) { // If the button is the "C" button, it should be placed on the second row, not the first row.
            y_non_numerical_buttons = 2;
            x_non_numerical_buttons = 0;
        }
        char label[2];
        sprintf(label, "%c", list_of_non_numerical_buttons[i]);
        GtkWidget *button = gtk_button_new_with_label(label);
        gtk_widget_set_size_request(button, 180, 50);
        gtk_grid_attach(GTK_GRID(grid), button, x_non_numerical_buttons, y_non_numerical_buttons, 1, 1);
        x_non_numerical_buttons++;
        non_numerical_buttons[i] = button; // Adds the buttons to the array of non-numerical buttons.
    }


    // Runs the GTK window
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
    }
