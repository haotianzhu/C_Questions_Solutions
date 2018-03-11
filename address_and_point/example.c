
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

int* p_add(int *a, int *b, int *c){
	a = malloc(sizeof(int));

	*a = 1;
	*b = 2;
	*c = 3;

	printf("In function: address of *a %p; address of a %p; value: %d\n", (void*)a, (void*)&a,*a);
	printf("In function: address of *b %p; address of b %p; value: %d\n", (void*)b, (void*)&b,*b);
	printf("In function: address of c %p; value: %d \n\n", (void*)c, *c);		

	return a;
}

int main(int argc, char const *argv[]){
	int *p1;
	int *p2;
	int p3;
	int *p4;

	p1 = 0;
	p2 = malloc(sizeof(int));
	p3 = 0;

	printf("Before: address of *p1 %p; address of p1 %p \n", (void*)p1, (void*)&p1 );
	printf("Before: address of *p2 %p; address of p2 %p \n", (void*)p2, (void*)&p2 );
	printf("Before: address of p3 %p\n\n", (void*)&p3 );

	p4 = p_add(p1,p2,&p3);

	printf("After: address of *p1 %p; address of p1 %p \n", (void*)p1, (void*)&p1 );
	printf("After: address of *p2 %p; address of p2 %p \n", (void*)p2, (void*)&p2 );
	printf("After: address of p3 %p\n\n", (void*)&p3 );	
	printf("address of p4: %p, value: %d\n",(void*)p4,*p4 );

	return 0;
}