
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>


#include "single_link_list.h"

int main(int argc, char const *argv[]){

	int array[3] = {1,2,3};
	sl_list *l1 = sll_init_empty();
	sl_list *l2 = sll_init(array,3);

	sll_retrieve(l1);
	sll_retrieve(l2);

	sll_append(l1, 11);
	sll_add(l1, 0, 99);
	sll_add(l1, 1, 55);

	sll_pop(l2);

	sll_retrieve(l1);
	sll_retrieve(l2);

	sll_concat(l1, l2, 2, 0);

	sll_retrieve(l1);
	sll_retrieve(l2);

	sll_concat(l1->next, l2, 2, 0);

	printf("---\n");
	sll_retrieve(l1);
	sll_retrieve(l2);

	sll_free(l1);
	sll_free(l2);


	return 0;
}