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
#ifndef LINES_H
#define LINES_H

#include <gtk/gtk.h>
#include "rules.h"

#define PACKAGE "lines"
#define LOCALEDIR "/usr/local/share/locale"
#include <libintl.h>
#define	_(str)	gettext(str)
#define __(str) (str)	
#define gettext_noop(str) (str)	

#define SCOREFILE	"/var/tmp/lines.hiscore"
#define HISCORESIZE	20

extern GtkWidget	*window; 

extern GtkWidget	*score_lab;
extern int		score;
extern int		looks; /* if TRUE, then show pixmaps, else numbers */
extern int		hints; /* either to show small balls or not */

extern GtkWidget	*buttons[SIZE][SIZE];
extern GtkWidget	*labels[SIZE][SIZE];
extern int		field[SIZE][SIZE];
extern GtkStyle		*styles[6];
extern GdkPixmap 	*gpix[];
extern GdkBitmap	*gmap[];
extern GdkPixmap 	*gsmallpix[];
extern GdkBitmap	*gsmallmap[];
extern 	struct xyc {int x, y, c;}	next_pops[POP_BALLS];

extern int 		undo_field[SIZE][SIZE];
extern struct xyc 	undo_pops[POP_BALLS];

void reset(void);
void pixmaps_init(void);
void pixmaps_free(void);
void show_label(void);
void redisplay(void);

#endif




