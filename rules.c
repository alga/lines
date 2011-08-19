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
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lines.h"
#include "rules.h"
#include "child.h"

#define ANIM_WAIT_USEC 20000

void anim_move_ball(GList *path)
{
    int x, y, x1, y1;

    x1 = (unsigned)(path->data) & 0xFFFF;
    y1 = (unsigned)(path->data) >> 16;
    path = g_list_remove(path, path->data);

    while(path) {
	x = (unsigned)(path->data) & 0xFFFF;
	y = (unsigned)(path->data) >> 16;
	swap_children(y, x, y1, x1);

	while (gtk_events_pending())
	    gtk_main_iteration();

    	usleep(ANIM_WAIT_USEC);  
	y1 = y;
	x1 = x;
	path = g_list_remove(path, path->data);
    }
}

int find_path(int y1, int x1, int y2, int x2)
{
    GList *queue = NULL, *node;
    unsigned int path[SIZE][SIZE];
    unsigned int distance[SIZE][SIZE];
    int i, j, x, y;

    for (i = 0; i < SIZE; i++)
	for (j = 0; j < SIZE; j++)  {
	    path[i][j] = i << 16 | j;
	    distance[i][j] = MAXINT;
	}
    distance[y1][x1] = 0;
    queue = g_list_append(NULL, (gpointer)(y1 << 16 | x1));

    while (queue) {
	x = (unsigned)(queue->data) & 0xFFFF;
	y = (unsigned)(queue->data) >> 16;
	node = queue;
	queue = g_list_remove_link(queue, node);
	g_list_free(node);

	/* up */
	if ( y && distance[y-1][x] > distance[y][x] + 1 && !field[y-1][x])
	{
	    distance[y-1][x] = distance[y][x] + 1;
	    path[y-1][x] = y << 16 | x;
	    queue = g_list_append(queue, (gpointer)((y-1) << 16 | x));
	}
	/* down */
	if ( y < SIZE - 1 && distance[y+1][x] > distance[y][x] + 1 && 
	     !field[y+1][x])
	{
	    distance[y+1][x] = distance[y][x] + 1;
	    path[y+1][x] = y << 16 | x;
	    queue = g_list_append(queue, (gpointer)((y+1) << 16 | x));
	}
	/* left */
	if ( x && distance[y][x-1] > distance[y][x] + 1 && !field[y][x-1])
	{
	    distance[y][x-1] = distance[y][x] + 1;
	    path[y][x-1] = y << 16 | x;
	    queue = g_list_append(queue, (gpointer)(y << 16 | (x-1)));
	}
	/* right */
	if ( x < SIZE - 1 && distance[y][x+1] > distance[y][x] + 1 && 
	     !field[y][x+1])
	{
	    distance[y][x+1] = distance[y][x] + 1;
	    path[y][x+1] = y << 16 | x;
	    queue = g_list_append(queue, (gpointer)(y << 16 | (x+1)));
	}
    } /* while */

    /* if we didn't reach the dest. */
    if (distance[y2][x2] == MAXINT)
	return FALSE;
    
    /* Okay, if we found it... */
    /* we have a reverse path */
    /* put it to a list */
    queue = g_list_prepend(queue, (gpointer)(y2 << 16 | x2) );
    while( x2 != x1 || y2 != y1 ) {
	x = path[y2][x2] & 0xFFFF;
	y = path[y2][x2] >> 16;
	queue = g_list_prepend(queue, (gpointer)(path[y2][x2]));
	x2 = x;
	y2 = y;
    } 

    /* and now move a ball  */
    anim_move_ball(queue);
    return TRUE;
}

int pop_new(void)
{
    int i,j,k, nr_free, rnd;
    GList *free_cells = NULL, *cell = NULL;

    for(i = 0; i < SIZE; i++)
	for(j = 0; j < SIZE; j++)
	    if(!field[i][j])
		free_cells = g_list_append( free_cells, 
					     (gpointer)(i << 16 | j));
    for(k = 0; k < POP_BALLS; k++)  {
	nr_free = g_list_length(free_cells);
	if(nr_free <= POP_BALLS)
	    return FALSE;
	if (next_pops[k].c && !field[next_pops[k].x][next_pops[k].y]) {
	    /* we have something planned && the place isn't taken yet */
	    field[next_pops[k].x][next_pops[k].y] = next_pops[k].c;
	    put_child(next_pops[k].x, next_pops[k].y);
	} else if (next_pops[k].c) {
	    /* Oops.  The place has already been taken */
	    rnd = (int)(((double)nr_free * rand() ) / (RAND_MAX + 1.0));
	    cell = g_list_nth( free_cells, 
			       rnd);
	    i = (unsigned)(cell->data) >> 16;
	    j = (unsigned)(cell->data) & 0xFFFF;
	    free_cells = g_list_remove_link(free_cells, cell);
	    g_list_free(cell);
	    field[i][j] = next_pops[k].c;
	    put_child(i,j);
	}
	next_pops[k].x = next_pops[k].y = next_pops[k].c = 0;
    }

    g_list_free(free_cells);
	
    return TRUE;
}

void next_pop()
{
    int i,j,k, nr_free, rnd;
    GList *free_cells = NULL, *cell = NULL;

    for(i = 0; i < SIZE; i++)
	for(j = 0; j < SIZE; j++)
	    if(!field[i][j])
		free_cells = g_list_append( free_cells, 
					     (gpointer)(i << 16 | j));
    for(k = 0; k < POP_BALLS; k++)  {
	nr_free = g_list_length(free_cells);
	if(!nr_free) {
	    next_pops[k].x = next_pops[k].y = next_pops[k].c = 0;
	    continue;
	}
	rnd = (int)(((double)nr_free * rand() ) / (RAND_MAX + 1.0));
	cell = g_list_nth( free_cells, 
			   rnd);
	next_pops[k].x = (unsigned)(cell->data) >> 16;
	next_pops[k].y = (unsigned)(cell->data) & 0xFFFF;
	next_pops[k].c = 1 + (int)(( 6.0 * rand()) / (RAND_MAX + 1.0));
	free_cells = g_list_remove_link(free_cells, cell);
	g_list_free(cell);
	put_child(next_pops[k].x, next_pops[k].y);
    }

    g_list_free(free_cells);	
}

int check_lines(void)
{
    GList 	*this = NULL, *all = NULL;
    int 	i, j, k, m; 
    int	dx, dy, x, y, colour, count, dscore = score;
    /*		RIGHT, 	RIGHT-DOWN, DOWN, 	LEFT-DOWN */ 
    int dxx[] = {	1, 	1, 	0, 	-1 };
    int dyy[] = {	0, 	1, 	1, 	1  };


    /* for all directions */
    for (k = 0; k < 4; k++) {
	dx = dxx[k];
	dy = dyy[k];
	this = NULL;

	/* scan the field */
	for (i = 0; i < SIZE; i++)
	    for (j = 0; j < SIZE; j++) {

		if (!(colour = field[i][j]))
		    continue;
		count = 1;
		x = j;
		y = i;

		/* 
		 * count how many balls of the same colour are in a
		 * line 
		 */
		while(1) {
		    x += dx;
		    y += dy;
		    if ( x < 0 || x >= SIZE || y < 0 || y >= SIZE ||
			 field[y][x] != colour )
			break;
		    /* if a ball has not yet been "chosen" in this
		     * direction
		     */
		    if ( g_list_find(this, (gpointer)(y << 16 | x))) 
			break;
		    count++;
		}

		if( count >= MIN_LINE_LENGTH ) { 
		    for (m  = 0; m < count; m++) 
			this = g_list_append( 
			    this, 
			    (gpointer)((i + m*dy) << 16 | (j + m*dx)));
		}
	    }
	all = g_list_concat(all, this);
    }

    /* If we've got anything, update the score */
    if ((count = g_list_length(all))) {
	score += (count - MIN_LINE_LENGTH + 1) * count;
	show_label();
    }
    /* now just remove all the listed balls...*/
    while ( all ) {
	j = (int)(all->data) & 0xFFFF;
	i = (int)(all->data) >> 16;
	this = all;
	all = g_list_remove_link(all, this);
	g_list_free_1(this);
	field[i][j] = 0;
	put_child(i, j);
    }
    return score - dscore;
}


