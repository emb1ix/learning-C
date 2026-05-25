#include "calculator.h"
#include <gtk/gtk.h>

long long numbers_to_calculate[512];
char operators_to_calculate[512];
int number_in_the_list = 0;
int operator_in_the_list = 0;
long long answer = 0;

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

    for (int i = 0; i < 512; i++) {
        numbers_to_calculate[i] = 0;
    }
    for (int i = 0; i < 512; i++) {
        operators_to_calculate[i] = 0;
    }
    numbers_to_calculate[0] = answer;
    answer = 0;
    number_in_the_list = 0;
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
