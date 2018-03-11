
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>


#include "single_link_list.h"

int main(int argc, char const *argv[]){
	int n[4] = {0,1,2,3};
	int m[5] = {3,77,123,222,99};

	sl_list * root = sll_init(n,4);
	sll_retrieve(root);
	sl_list *sc_root = sll_init(m, 4);
	sll_retrieve(sc_root);
	int a = sll_concat(root, sc_root, 4,1);
	sll_retrieve(root);
	sll_add(root,-1, 9999);
	sll_retrieve(root);
	// sll_remove(root,2);
	// sll_retrieve(root);	
	sll_free(root);
	sll_free(sc_root);
	return 0;
}