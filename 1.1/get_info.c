
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

/*-------------------
man getrusage
-------------------*/
#include <sys/time.h>
#include <sys/resource.h>
#define   RUSAGE_SELF     0
#define   RUSAGE_CHILDREN     -1


int main( void )
{
    clock_t start, stop;
    long int x;
    double duration;


    start = clock();  // get number of ticks before loop

    for( x = 0; x < 10000; x++ );
    // sleep(100);

    stop = clock();  // get number of ticks after loop

    // calculate time taken for loop
    duration = ( double ) ( stop - start ) / CLOCKS_PER_SEC;

    struct rusage  my_rusage_end;
    int status  = getrusage(RUSAGE_SELF,&my_rusage_end);
	struct timeval user_time_end, sys_time_end;
	user_time_end = my_rusage_end.ru_utime;
	sys_time_end = my_rusage_end.ru_utime;

	double user_duration = user_time_end.tv_sec  + ((user_time_end.tv_usec )/1000000.0);
	double sys_duration  = sys_time_end.tv_sec + ((sys_time_end.tv_usec )/1000000.0);

    printf("user_time %lf,sys_time %lf \n",user_duration,sys_duration );
	printf( "\nThe number of seconds for loop to run was %lf\n", duration );


    return 0;

}