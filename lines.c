/*****************************************************************************
 *
 * lines  -- a game
 *
 * (c) 1999 Albertas Agejevas <alga@pub.osf.lt>
 * 
 * This program is free software. You can use it under the conditions of
 * the GNU General Public Licence version 2
 *
 * History:
 * 1999 03 25	Started...
 *
 *****************************************************************************
 */
 
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "lines.h"
#include "handlers.h"
#include "child.h"
#include "rules.h"
#include "balls.h"
#include "smallballs.h"
#include "menu.h"

GtkWidget	*window; 
GtkWidget	*score_lab;
GtkWidget	*buttons[SIZE][SIZE];
GtkWidget	*labels[SIZE][SIZE];

/* Global flags */
int		score = 0;
int		hints = 0;

/* The playing field and the balls to pop up next */
int		field[SIZE][SIZE];
struct xyc	next_pops[POP_BALLS];

/* Tne one-step undo information */
int		undo_field[SIZE][SIZE];
struct xyc	undo_pops[POP_BALLS];


GtkStyle	*styles[6];
GtkStyle	*smallstyles[6];
GdkPixmap	*gpix[6];
GdkBitmap	*gmap[6];
GdkPixmap	*gsmallpix[6];
GdkBitmap	*gsmallmap[6];

int main(int argc, char *argv[])
{

    GtkWidget *table, *box;
    GtkStyle *style;
    GdkColor col;
    int i,j;

    gtk_init(&argc, &argv);
    srand(time(NULL));

    bindtextdomain (PACKAGE, ".");
    textdomain(PACKAGE);

    /*
     * Main window
     */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_container_border_width(GTK_CONTAINER (window), 0);
    gtk_signal_connect (GTK_OBJECT (window), "delete_event",
			GTK_SIGNAL_FUNC (delete_event), GTK_OBJECT(window));
    gtk_window_set_title(GTK_WINDOW(window), "Lines");
    gtk_widget_show(window);
    gtk_widget_hide(window);

    pixmaps_init();

    /* Score: 123456 */
    score_lab = gtk_label_new(_("Score: 0"));
    style = gtk_style_copy(score_lab->style);
    /* font
    gdk_font_unref(style->font);
    style->font  =
	gdk_font_load("-*-helvetica-*-r-*-*-24-*-*-*-*-*-*-*");
    */
    col.red = 0;
    col.green = 0;
    col.blue = 65535;
    style->fg[GTK_STATE_NORMAL] = col;
    gtk_style_unref(score_lab->style);
    score_lab->style = style;
    gtk_widget_show(score_lab);

    /* styles for the ball labels */
    for (i = 0; i < SIZE; i++) {
	styles[i] = gtk_style_copy(score_lab->style);
        /*
	gdk_font_unref(styles[i]->font);
	styles[i]->font =
	    gdk_font_load("-adobe-courier-bold-r-*-*-24-*-*-*-*-*-*-*");
        */
/*  	colors[i].red = colors[i].blue = colors[i].green = i * 1000; */
/*  	styles[i]->fg[GTK_STATE_NORMAL] = colors[i]; */
    }


    table = gtk_table_new(SIZE, SIZE, TRUE);
    for (i = 0; i < SIZE; i++)
	for (j = 0; j < SIZE; j++) {
	    labels[i][j] = new_child(i,j);
	    buttons[i][j] = gtk_toggle_button_new();
	    gtk_container_add(GTK_CONTAINER(buttons[i][j]),
			      labels[i][j]);
	    gtk_table_attach_defaults( GTK_TABLE(table),
				       buttons[i][j],
				       i, i + 1,
				       j, j + 1);
	    gtk_signal_connect(GTK_OBJECT(buttons[i][j]),
			       "clicked",
			       GTK_SIGNAL_FUNC(click),
			       (gpointer)(i << 16 | j));
	    gtk_widget_show(buttons[i][j]);
	    gtk_widget_show(labels[i][j]);
	}

    box = gtk_vbox_new(FALSE,2);
    gtk_box_pack_start(GTK_BOX(box), menu_init(window), FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(box), score_lab, FALSE, FALSE, 2);
    gtk_box_pack_start(GTK_BOX(box), table, TRUE, TRUE, 2);
    gtk_widget_show(box);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_widget_set_usize(GTK_WIDGET(table),280,280);  
    gtk_widget_show(table);
    gtk_widget_show(window);

    next_pop();
    pop_new();
    next_pop();

    gtk_main();

    return 0;
}

void pixmaps_init(void)
{
    int i;
    for (i = 0; i < 6; i++) {
        gpix[i] = gdk_pixmap_create_from_xpm_d(window->window, gmap,
                      &window->style->bg[GTK_STATE_NORMAL], *balls[i]);
        gsmallpix[i] = gdk_pixmap_create_from_xpm_d(window->window, gsmallmap,
                      &window->style->bg[GTK_STATE_NORMAL], *smallballs[i]);
    }
}

void pixmaps_free(void)
{
    int i;
    for (i = 0; i < 6; i++) {
	gdk_pixmap_unref(gpix[i]);
	gdk_bitmap_unref(gmap[i]);
    }
}
    
void reset(void)
{
    int i;
    for(i = SIZE * SIZE - 1; i >= 0; i--)
	(*field)[i] = 0;
    score = 0;
    next_pop();
    pop_new();
    next_pop();
    redisplay(); 
}

void redisplay(void)
{
    int i,j;
    for (i = 0; i < SIZE; i++)
	for (j = 0; j < SIZE; j++)
	    put_child(i, j);
    show_label();
}

void show_label(void)
{
    char buf[20];
    *buf = 0;

    sprintf(buf, _("Score: %d"), score);
    gtk_label_set(GTK_LABEL(score_lab), buf);
}

void save_undo()
{
    memcpy(undo_field, field, sizeof undo_field);
    memcpy(undo_pops, next_pops, sizeof undo_pops);
}
