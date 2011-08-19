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

#ifndef LINES_RULES_H
#define LINES_RULES_H
#include <values.h>

#define MIN_LINE_LENGTH 5
#define SIZE		10
#define POP_BALLS	3

int 	find_path(int y1, int x1, int y2, int x2);
int 	pop_new(void);
void 	next_pop(void);
int	check_lines(void);

#endif
