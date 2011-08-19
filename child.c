/*****************************************************************************
 *
 * lines  -- a game
 *
 * (c) 1999 Albertas Agejevas <alga@pub.osf.lt>
 * 
 * This program is free software. You can use it under the conditions of
 * the GNU General Public Licence version 2
 *
 *
 *****************************************************************************
 */
#include "lines.h"
#include "child.h"
#include <stdio.h>

GtkWidget *new_child( int i, int j)
{
    static GtkWidget *child;
    gchar buffer[5] = { 0, };
    int k;

    if(looks) {
	if(field[i][j]) 
	    child = gtk_pixmap_new(gpix[field[i][j]-1], gmap[field[i][j]-1]);
	else {
	    for(k = 0; k < POP_BALLS; k++)
		if( hints && next_pops[k].c &&
		    next_pops[k].x == i && next_pops[k].y == j) {
		    child = gtk_pixmap_new(gsmallpix[next_pops[k].c-1], 
					   gsmallmap[next_pops[k].c-1]);
		    break;
		}
	    if (k == POP_BALLS)
		child = gtk_label_new(" ");
	}
    } else {
	if(field[i][j])
	    sprintf(buffer, "%d", field[i][j]);
	child = gtk_label_new(buffer);
	if(field[i][j]) {
	    gtk_style_unref(child->style);
	    child->style = gtk_style_copy(styles[field[i][j]-1]);
	}
    }
    if(!child)
	*(int*)child = (int)"Crash!!!"; /* a segfault for debugging
					 * purposes */
    return child;
} 

void swap_children(int y1, int x1, int y2, int x2)
{
    int tmp;

    if(x1 == x2 && y1 == y2)
	return;

    tmp = field[y1][x1];
    field[y1][x1] = field[y2][x2];
    field[y2][x2] = tmp;

    put_child(y1, x1);
    put_child(y2, x2);
}

void put_child(int y, int x)
{
    if( buttons[y][x] && labels[y][x]) 
	gtk_container_remove( GTK_CONTAINER(buttons[y][x]),
			      labels[y][x]);
    labels[y][x] = new_child(y, x);
    gtk_container_add( GTK_CONTAINER(buttons[y][x]),
		       labels[y][x]);
    gtk_widget_show(labels[y][x]);

}













