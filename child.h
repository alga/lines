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
#ifndef LINES_CHILD_H
#define LINES_CHILD_H

void 		swap_children(int y1, int x1, int y2, int x2);
GtkWidget	*new_child(int i, int j);
void 		put_child(int y, int x);

#endif

