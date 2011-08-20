#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "lines.h"
#include "hiscore.h"

static void new_cb(GtkWidget* w, gpointer data);
static void about_cb(GtkWidget* w, gpointer data);
static void switch_cb(GtkWidget* w, gpointer data);
static void hints_cb(GtkWidget* w, gpointer data);
static void redraw_cb(GtkWidget* w, gpointer data);
static void hiscore_cb(GtkWidget* w, gpointer data);
static void undo_cb(GtkWidget* w, gpointer data);

int looks = 1;
static GtkWidget *undo_menu_item;

static GtkItemFactoryEntry menu_items[] = {
    { __("/_Game"), 	"<alt>G", 	NULL, 	0, 	"<Branch>" 	},
    { __("/Game/_New"), "n", 	new_cb,		0, 	"<Item>" 	},
    { "/Game/_Undo",	"<control>Z", undo_cb,	0,	"<Item>" 	},
    { __("/Game/_About"), NULL,	about_cb,	0,	"<Item>" 	},
    { __("/Game/_Hiscore"), NULL,hiscore_cb,	0,	"<Item>" 	},
    { __("/Game/_Redraw"), "r",	redraw_cb,	0, 	"<Item>" 	},
    { __("/Game/separator"),NULL,	NULL,	0,	"<Separator>"	},
    { __("/Game/_Quit"),"q",	gtk_main_quit,	0,	"<Item>"	},

    { __("/_Options"),	"<alt>V",NULL,		0,	"<Branch>" 	},
    { __("/Options/_Colours"),"b",switch_cb,	1,	"<RadioItem>"	},
    { __("/Options/_Numbers"),"n",switch_cb,	0,__("/Options/Colours")},
    { __("/Options/_Hints"),NULL, hints_cb,	1,	"<CheckItem>" 	}

};

static void new_cb(GtkWidget* w, gpointer data)
{
    reset();
}

static void redraw_cb(GtkWidget* w, gpointer data)
{
    redisplay();
}

static void hints_cb(GtkWidget* w, gpointer data)
{
    hints = !hints;
    redisplay();
}


static void switch_cb(GtkWidget* w, gpointer data)
{
    looks = (int) data;
    redisplay();
}

static void hiscore_cb(GtkWidget* w, gpointer data)
{
    show_hiscore();
}

static void undo_cb(GtkWidget* w, gpointer data)
{
    memcpy(field, undo_field, sizeof field);
    memcpy(next_pops, undo_pops, sizeof next_pops);

    enable_undo(FALSE);
    redisplay();
}

void del(GtkWidget *w, GdkEvent *e, gpointer data)
{
    gtk_widget_destroy(GTK_WIDGET(data));
}
void del1(GtkWidget *w, gpointer data)
{
    gtk_widget_destroy(GTK_WIDGET(data));
}
static void about_cb(GtkWidget* w, gpointer data)
{
    /* display an About window  */
    GtkWidget *about;
    GtkWidget *ok, *box, *label;

    about = gtk_window_new(GTK_WINDOW_POPUP);
    gtk_window_set_position(GTK_WINDOW(about), GTK_WIN_POS_MOUSE);
    gtk_container_border_width(GTK_CONTAINER(about), 5);
    box = gtk_vbox_new(FALSE,2);
    ok = gtk_button_new_with_label(_("OK"));
    label = gtk_label_new(_("Lines\n\nThis program is written by \n"
			  "Albertas Agejevas\n\n"
			  "Share and enjoy!"));
    gtk_box_pack_start(GTK_BOX(box), label, TRUE, TRUE, 3); 
    gtk_box_pack_start(GTK_BOX(box), ok, FALSE, FALSE, 3);
    gtk_container_add(GTK_CONTAINER(about), box);
    gtk_signal_connect(GTK_OBJECT(about), "delete_event",
		       GTK_SIGNAL_FUNC(del), about);
    gtk_signal_connect(GTK_OBJECT(ok), "clicked",
		       GTK_SIGNAL_FUNC(del1), about);
    gtk_widget_show(about);
    gtk_widget_show(box);
    gtk_widget_show(label);
    gtk_widget_show(ok);
}

GtkWidget *menu_init(GtkWidget *window)
{
    GtkWidget *w;
    GtkAccelGroup *accel;
    GtkItemFactory *itemf;
    GtkItemFactoryEntry *menu;
    int i;
    
    accel = gtk_accel_group_new();
    if (!(menu = (GtkItemFactoryEntry*) malloc(sizeof(menu_items)))) {
	perror("menu_init");
	exit(1);
    }

    for (i = 0; i < sizeof(menu_items)/sizeof(menu_items[0]); i++) {
	menu[i] = menu_items[i];
	menu[i].path = gettext(menu_items[i].path);
	menu[i].item_type = gettext(menu_items[i].item_type);
    }

    itemf = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<main>", accel);
    gtk_item_factory_create_items(itemf, sizeof(menu_items) /
				  sizeof(menu_items[0]), menu, NULL);

    /* gtk_accel_group_attach(accel, GTK_OBJECT(window)); */
    
    w = gtk_item_factory_get_widget(itemf, _("/Options/Hints"));
    GTK_CHECK_MENU_ITEM(w)->active =  hints;

    undo_menu_item = gtk_item_factory_get_widget(itemf, "/Game/Undo");

    w = gtk_item_factory_get_widget(itemf, "<main>");
    gtk_widget_show(w);

//    enable_undo(FALSE);
//    enable_undo(TRUE);
    GTK_WIDGET_STATE(undo_menu_item) = GTK_STATE_INSENSITIVE;

    free(menu);

    return w;
}

void enable_undo(gboolean b)
{
    gtk_widget_set_state(undo_menu_item, 
			 b ? GTK_STATE_ACTIVE : GTK_STATE_INSENSITIVE);
}






