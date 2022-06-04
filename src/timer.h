#pragma once
#include <stdio.h>
#include <time.h>

static time_t start,stop;

static clock_t start_time;


static double elapsed;

/*-----holding the current system time-----*/
void start_timer(void)
{
     time(&start);
     start_time = clock();
}

/*------returns the elapsed CPU time--------*/
double elapsed_time(void)
{
    elapsed = (double)(clock()- start_time);
    time(&stop);
    return elapsed / CLOCKS_PER_SEC;
}
