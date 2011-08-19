/*****************************************************************************
 *
 * lines  -- a game
 *
 * (c) 1999 Albertas Agejevas <alga@pub.osf.lt>
 * 
 * This program is free software. You can use it under the conditions of
 * the GNU General Public Licence version 2
 *
 *****************************************************************************
 */
#ifndef LINES_HANDLERS_H
#define LINES_HANDLERS_H
#include <gtk/gtk.h>

void 	delete_event(GtkWidget *widget, GdkEvent *e, gpointer data);
void 	click(GtkWidget *widget, gpointer data);

#endif



