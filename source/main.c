#include <stdio.h>
#include <gtk/gtk.h>

long long numbers_to_calculate[512]; // Stores the numbers, that the user inputs
char operators_to_calculate[512]; // Stores the operators, that the user inputs
int number_in_the_list = 0;
int operator_in_the_list = 0;

long long answer = 0;

void plus() {
    
}

// Runs all the logic for button presses
void button_0_clicked(GtkWidget *widget, gpointer button_0_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 0;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_0_data), current_number);
}

void button_1_clicked(GtkWidget *widget, gpointer button_1_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 1;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_1_data), current_number);
}

void button_2_clicked(GtkWidget *widget, gpointer button_2_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 2;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_2_data), current_number);
}

void button_3_clicked(GtkWidget *widget, gpointer button_3_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 3;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_3_data), current_number);
}

void button_4_clicked(GtkWidget *widget, gpointer button_4_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 4;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_4_data), current_number);
}

void button_5_clicked(GtkWidget *widget, gpointer button_5_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 5;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_5_data), current_number);
}

void button_6_clicked(GtkWidget *widget, gpointer button_6_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 6;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_6_data), current_number);
}

void button_7_clicked(GtkWidget *widget, gpointer button_7_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 7;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_7_data), current_number);
}

void button_8_clicked(GtkWidget *widget, gpointer button_8_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 8;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_8_data), current_number);
}

void button_9_clicked(GtkWidget *widget, gpointer button_9_data) {
    char current_number[20];
    numbers_to_calculate[number_in_the_list] = numbers_to_calculate[number_in_the_list] * 10 + 9;
    sprintf(current_number, "%lld", numbers_to_calculate[number_in_the_list]);
    gtk_entry_set_text(GTK_ENTRY(button_9_data), current_number);
}

// ------------------------------------------------------------------------------

void button_C_clicked(GtkWidget *widget, gpointer button_C_data) {
    gtk_entry_set_text(GTK_ENTRY(button_C_data), "");
    for (int i = 0; i < 512; i++) {
        numbers_to_calculate[i] = 0;
    }
    for (int i = 0; i < 512; i++) {
        operators_to_calculate[i] = 0;
    }
    answer = 0;
    number_in_the_list = 0;
    operator_in_the_list = 0;
}

void button_equals_clicked(GtkWidget *widget, gpointer button_equals_data) {

    answer = numbers_to_calculate[0];

    for (int i = 0; i <= number_in_the_list; i++) {

            if (operators_to_calculate[i-1] == '+') {
                answer = answer + numbers_to_calculate[i];
            }
            else if (operators_to_calculate[i-1] == '-') {
                answer = answer - numbers_to_calculate[i];
            }
            else if (operators_to_calculate[i-1] == '*') {
                answer = answer * numbers_to_calculate[i];
            }
            else if (operators_to_calculate[i-1] == '/') {
                answer = answer / numbers_to_calculate[i];
            }
    }
    char answer_str[256];
    sprintf(answer_str, "%lld", answer);
    gtk_entry_set_text(GTK_ENTRY(button_equals_data), answer_str);

    numbers_to_calculate[0] = answer;
    answer = 0;
    number_in_the_list = 1;
    operator_in_the_list = 0;
}

void button_multiply_clicked(GtkWidget *widget, gpointer button_multiply_data) {
    gtk_entry_set_text(GTK_ENTRY(button_multiply_data), "*");

    operators_to_calculate[operator_in_the_list] = '*';
    operator_in_the_list++;
    number_in_the_list++;
}

void button_plus_clicked(GtkWidget *widget, gpointer button_plus_data) {
    gtk_entry_set_text(GTK_ENTRY(button_plus_data), "+");
    operators_to_calculate[operator_in_the_list] = '+';
    operator_in_the_list++;

    number_in_the_list++;

}

void button_minus_clicked(GtkWidget *widget, gpointer button_minus_data) {
    gtk_entry_set_text(GTK_ENTRY(button_minus_data), "-");

    operators_to_calculate[operator_in_the_list] = '-';
    operator_in_the_list++;
    number_in_the_list++;
}

void button_divide_clicked(GtkWidget *widget, gpointer button_divide_data) {
    gtk_entry_set_text(GTK_ENTRY(button_divide_data), "/");

    operators_to_calculate[operator_in_the_list] = '/';
    operator_in_the_list++;
    number_in_the_list++;
}

// Makes an array for the functions of the numerical buttons.
void (*buttons_clicked[16])(GtkWidget *, gpointer) = {
    button_0_clicked,
    button_1_clicked,
    button_2_clicked,
    button_3_clicked,
    button_4_clicked,
    button_5_clicked,
    button_6_clicked,
    button_7_clicked,
    button_8_clicked,
    button_9_clicked,
// ---------------------------
    button_C_clicked,
    button_equals_clicked,
    button_multiply_clicked,
    button_plus_clicked,
    button_minus_clicked,
    button_divide_clicked

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
        g_signal_connect(non_numerical_buttons[i], "clicked", G_CALLBACK(buttons_clicked[i + 10]), textfield); // 10 is the amount of numerical buttons
    }

    // Runs the GTK window
    gtk_widget_show_all(window);
    gtk_main();


    return 0;
    }