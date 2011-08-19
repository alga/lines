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

