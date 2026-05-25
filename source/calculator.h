#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include <gtk/gtk.h>

extern long long numbers_to_calculate[512];
extern char operators_to_calculate[512];
extern int number_in_the_list;
extern int operator_in_the_list;
extern long long answer;


extern void (*buttons_clicked[16])(GtkWidget *, gpointer);
#endif

