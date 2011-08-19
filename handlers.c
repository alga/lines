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
#include "handlers.h"
#include "rules.h"
#include "hiscore.h"
#include "lines.h"
#include <stdio.h>

void delete_event(GtkWidget *widget, GdkEvent *e, gpointer data)
{
    gtk_main_quit();
}

void click(GtkWidget *widget, gpointer data)
{
    int i,j;
    static int second;
    static int x1, y1, click_lock;

    if(click_lock)
	return;
    i = (unsigned)data >> 16;
    j = (unsigned)data & 0xFFFF;

    /* is one ball selected yet ? */
    if( !second ) {
	if(!field[i][j]) {
	    /* if an empty square was pressed, we just 
	     * pop it back
	     */
	    click_lock = TRUE;
	    gtk_toggle_button_set_state(
		GTK_TOGGLE_BUTTON(buttons[i][j]), 
		FALSE);
	    click_lock = FALSE;
	    return;
	}   
	second = TRUE;
	x1 = j;
	y1 = i;
    } else if (second) {
	if(x1 == j && y1 == i) {
	    second = FALSE;
	    return;
	}
	click_lock = TRUE;
	gtk_toggle_button_set_state(
	    GTK_TOGGLE_BUTTON(buttons[y1][x1]), 
	    FALSE);
	if(!field[i][j])
	    gtk_toggle_button_set_state(
		GTK_TOGGLE_BUTTON(buttons[i][j]), 
		FALSE);
	else {
	    x1 = j;
	    y1 = i;
	    click_lock = FALSE;
	    return;
	}
	click_lock = FALSE;

	save_undo();
	if( find_path(y1, x1, i, j) && !check_lines()) {
	    if (pop_new() == FALSE) {
		game_over();
	    } 
	    next_pop();
	    check_lines();
	    enable_undo(TRUE);
	}

	second = FALSE;
    }
    
}






