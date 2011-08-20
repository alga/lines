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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lines.h"
#include "hiscore.h"

void hiscore_ok(GtkWidget *widget, gpointer data);
void show_hiscore();
int read_hiscore();
int write_hiscore();
void add_hiscore(int score);

static GtkWidget *list;

void game_over()
{
    show_hiscore();
    add_hiscore(score);
    write_hiscore();
    reset();
}

void hiscore_ok(GtkWidget *widget, gpointer data){
    gtk_widget_destroy(GTK_WIDGET(data));
}


void show_hiscore()
{
    GtkWidget *hiscore, *ok;

    hiscore = gtk_dialog_new();
    ok = gtk_button_new_with_label(_("OK"));

    list = gtk_clist_new(3);
    gtk_clist_set_column_title(GTK_CLIST(list), 0, _("Username"));
    gtk_clist_set_column_title(GTK_CLIST(list), 1, _("Date"));
    gtk_clist_set_column_title(GTK_CLIST(list), 2, _("Score"));
    gtk_clist_column_titles_show(GTK_CLIST(list));
    gtk_clist_set_column_width(GTK_CLIST(list),0,6 * strlen(_("Username")));
    gtk_clist_set_column_width(GTK_CLIST(list),1,170);
    gtk_clist_set_column_width(GTK_CLIST(list),2,8 * strlen(_("Score")));

    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(hiscore)->vbox), list);
    gtk_container_add(GTK_CONTAINER(GTK_DIALOG(hiscore)->action_area), ok);
    gtk_window_set_modal(GTK_WINDOW(hiscore), TRUE);
    gtk_signal_connect(GTK_OBJECT(ok), "clicked", (GCallback) hiscore_ok, hiscore);
 
    read_hiscore();
    gtk_widget_show_all(hiscore);    
}

int read_hiscore()
{
    FILE	*f;
    int 	count	=	0;
    gchar 	*buffer[3];
    char 	buf[80];
    int 	i;

    if(!(f = fopen(SCOREFILE, "r")))
	return 0;

    for (i=0; i < HISCORESIZE; i++) {
	fgets(buf, sizeof buf, f);
	buffer[0] = strtok(buf,  "\t\n");
	buffer[1] = strtok(NULL, "\t\n");
	buffer[2] = strtok(NULL, "\t\n");
	if (!buffer[0] || !buffer[1] || !buffer[2]) {
	    buffer[0] = buffer[1] = buffer[2] = "-";
	}
	if (buffer[0] && *buffer[0]) {
	    gtk_clist_append(GTK_CLIST(list), buffer);
	}
	*buf = 0;
    }
    fclose(f);
    return count;
}

void add_hiscore(int score)
{
    gchar 	scorebuf[80];
    gchar	*scorestr;
    time_t 	t;
    GtkStyle 	*style;
    GdkColor 	color;
    gchar 	*buffer[3];
    int		i;

    for (i=0; i < HISCORESIZE; i++) {
	gtk_clist_get_text(GTK_CLIST(list), i, 2, &scorestr); 
	if (score > atoi(scorestr)) {
	    color.red = 65535;
	    color.green = 0;
	    color.blue = 0;
	    style = gtk_style_new();
	    style->fg[GTK_STATE_NORMAL] = color;

	    sprintf(scorebuf, "%d", score);
	    buffer[2] = scorebuf;
	    t = time(NULL);
	    buffer[1] = ctime(&t);
	    buffer[0] = getenv("USER");

	    buffer[1][strlen(buffer[1]) - 1] = 0;

	    gtk_clist_insert(GTK_CLIST(list), i, buffer);
	    gtk_clist_set_row_style(GTK_CLIST(list), i, style);
	    gtk_clist_remove(GTK_CLIST(list), HISCORESIZE);

	    return;
	}
    }
}

int write_hiscore()
{
    FILE *f;
    int i;
    gchar *name, *date, *score;

    if(!(f = fopen(SCOREFILE, "w")))
	return 0;

    for(i = 0; i < GTK_CLIST(list)->rows; i++)
    {
	gtk_clist_get_text(GTK_CLIST(list), i, 0, &name); 
	gtk_clist_get_text(GTK_CLIST(list), i, 1, &date); 
	gtk_clist_get_text(GTK_CLIST(list), i, 2, &score); 
	fprintf( f, "%s\t%s\t%s\n", name, date, score);
    } 
    fclose(f);
    return i;
}





