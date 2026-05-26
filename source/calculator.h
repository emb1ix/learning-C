#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include <gtk/gtk.h>

extern void (*buttons_clicked[20])(GtkWidget *, gpointer);
extern void (render_buttons(GtkWidget *grid));
#endif

