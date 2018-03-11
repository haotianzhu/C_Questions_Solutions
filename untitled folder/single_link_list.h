
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>





struct _Node{
	int id; // Node id
	int val; //address 
	struct _Node *next;
};

typedef struct _Node sl_list;

sl_list* sll_init_empty();
sl_list* sll_init( int* array, int length);
void sll_add(sl_list *current,int index,int val);
void sll_append(sl_list *current,int val);
int sll_remove(sl_list *current,int index);
int sll_pop(sl_list *current);
void sll_retrieve(sl_list *root);
void sll_free(sl_list *root);
int sll_size(sl_list *root);
int sll_get(sl_list *root,int index);
int sll_concat(sl_list *current,sl_list *next,int size, int null_flag);
