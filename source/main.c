#include <stdio.h>
#include <gtk/gtk.h>

int numbers_to_calculate[512]; // Stores the numbers that the user inputs
int number_in_the_list = 0;

// Runs all the logic for button presses
void button_0_clicked(GtkWidget *widget, gpointer button_0_data) {
    gtk_entry_set_text(GTK_ENTRY(button_0_data), "0");
    numbers_to_calculate[number_in_the_list++] = 0;
}

void button_1_clicked(GtkWidget *widget, gpointer button_1_data) {
    gtk_entry_set_text(GTK_ENTRY(button_1_data), "1");
    numbers_to_calculate[number_in_the_list++] = 1;
}

void button_2_clicked(GtkWidget *widget, gpointer button_2_data) {
    gtk_entry_set_text(GTK_ENTRY(button_2_data), "2");
    numbers_to_calculate[number_in_the_list++] = 2;
}

void button_3_clicked(GtkWidget *widget, gpointer button_3_data) {
    gtk_entry_set_text(GTK_ENTRY(button_3_data), "3");
    numbers_to_calculate[number_in_the_list++] = 3;
}

void button_4_clicked(GtkWidget *widget, gpointer button_4_data) {
    gtk_entry_set_text(GTK_ENTRY(button_4_data), "4");
    numbers_to_calculate[number_in_the_list++] = 4;
}

void button_5_clicked(GtkWidget *widget, gpointer button_5_data) {
    gtk_entry_set_text(GTK_ENTRY(button_5_data), "5");
    numbers_to_calculate[number_in_the_list++] = 5;
}

void button_6_clicked(GtkWidget *widget, gpointer button_6_data) {
    gtk_entry_set_text(GTK_ENTRY(button_6_data), "6");
    numbers_to_calculate[number_in_the_list++] = 6;
}

void button_7_clicked(GtkWidget *widget, gpointer button_7_data) {
    gtk_entry_set_text(GTK_ENTRY(button_7_data), "7");
    numbers_to_calculate[number_in_the_list++] = 7;
}

void button_8_clicked(GtkWidget *widget, gpointer button_8_data) {
    gtk_entry_set_text(GTK_ENTRY(button_8_data), "8");
    numbers_to_calculate[number_in_the_list++] = 8;
}

void button_9_clicked(GtkWidget *widget, gpointer button_9_data) {
    gtk_entry_set_text(GTK_ENTRY(button_9_data), "9");
    numbers_to_calculate[number_in_the_list++] = 9;
}

// Makes an array for the functions of the numerical buttons.
void (*buttons_clicked[10])(GtkWidget *, gpointer) = {
    button_0_clicked,
    button_1_clicked,
    button_2_clicked,
    button_3_clicked,
    button_4_clicked,
    button_5_clicked,
    button_6_clicked,
    button_7_clicked,
    button_8_clicked,
    button_9_clicked
};

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

    
    // Creates a textfield and adds it to the grid
    GtkWidget *textfield = gtk_entry_new();
    gtk_widget_set_size_request(textfield, 180, 175);
    gtk_grid_attach(GTK_GRID(grid), textfield, 0, 0, 3, 1);


    // Creates an array to store the numerical buttons
    GtkWidget *number_buttons[10];
    GtkWidget *non_numerical_buttons[7];

    // Adds all the numerical buttons (with the exception of 0) to the grid
    int amount_of_y_rows = 7;
    int amount_of_runs = 0;
    for (int y = 2; y < 5; y++) {
        for (int x = 0; x < 3; x++) {
        char label[8];

        char label_for_signal[20];
        int y_backwards = amount_of_y_rows - y; // Draws them "upside down", so that they are drawn from the bottom up.
        amount_of_runs++;
        sprintf(label, "%d", (amount_of_runs)); // Gives them their text label
        GtkWidget *button = gtk_button_new_with_label(label);
        gtk_widget_set_size_request(button, 180, 100);  // Width, Height in pixels
        gtk_grid_attach(GTK_GRID(grid), button, x, y_backwards, 1, 1);
        number_buttons[amount_of_runs] = button; // Adds the buttons to the array of numerical buttons.
        sprintf(label_for_signal, "button_%d_clicked", amount_of_runs);
        g_signal_connect(number_buttons[amount_of_runs], "clicked", G_CALLBACK(buttons_clicked[amount_of_runs]), textfield);
    }
    }

    // Adds the 0 button to the grid
    GtkWidget *button = gtk_button_new_with_label("0");
    gtk_widget_set_size_request(button, 180, 100);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 3, 1);
    number_buttons[0] = button; // Adds the 0 button to the array of numerical buttons
    g_signal_connect(number_buttons[0], "clicked", G_CALLBACK(buttons_clicked[0]), textfield);

    // Creates the non-numerical buttons
    const char list_of_non_numerical_buttons[] = {'C', '=', '*', '+', '-', '/'};

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