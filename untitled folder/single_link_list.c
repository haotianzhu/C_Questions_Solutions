
#include "single_link_list.h"


#define MYERR(...) do { \
    printf ("@ %s (%d): ", __FILE__, __LINE__); \
    printf (__VA_ARGS__); \
    exit(EXIT_FAILURE);\
} while (0)



/*-------------------
struct _Node{
	int id; // Node id
	int val; //address 
	_Node *next;
};
-------------------*/
extern int errno;
static sl_list* _sll_get(sl_list*root,int size,int null_flag);
static void _sll_concat(sl_list *current,sl_list *add,sl_list *end);
static int _sll_remove(sl_list *current,sl_list *next);
static void _sll_add(sl_list *current,sl_list *next);



/*-------------------
sl_list *root => head of list
index => list[index], index from 0 to (size-1)
null_flag => 0 show error if out of index; 1 retuen NULL instead of error
-------------------*/
static
sl_list* _sll_get(sl_list* root,int index, int null_flag){

	if(index < 0){
		MYERR("index should be >= 0\n");
	}

	if(null_flag!=0 && null_flag != 1){
		MYERR("flag shoul be 0 or 1\n");
	}


	sl_list *current = root;

	int i = 0;
	for (i = 0; i < index && current; i++){
		current = current->next;
	}

	if(!null_flag){
		if(!current){
			MYERR("out of index\n");
		}
	}

	return current;
}



static
int _sll_remove(sl_list *current,sl_list *next){
	current->next = next->next;
	int re = next->val;
	next = NULL;
	return re;
}



static
void _sll_concat(sl_list *current,sl_list *add,sl_list *end){
	sl_list *temp = current->next;
	current->next = add;
	end->next = temp;
}



static
void _sll_add(sl_list *current,sl_list *next){
	sl_list *temp = current->next;
	current->next = next;
	next->next = temp;
}

sl_list* sll_init_empty(){

	sl_list *root = malloc(sizeof(sl_list));
	if(!root){
		MYERR("No memory to malloc\n");
	}
	root->val = 0;
	root->next = 0;
	return root;
}


sl_list* sll_init( int* array, int length){

	if(length < 1){
		MYERR("length should be >= 1\n");
	}

	sl_list **list = malloc(sizeof(sl_list *)*length);

	if(!list){
		MYERR("No memory to malloc\n");
	}
	for (int i = 0; i < length; i++){
		list[i] = malloc(sizeof(sl_list));
	}

	sl_list *root = &(list[0][0]);

	for (int i = 0; i < length; i++){
		(*(list+i))->val = array[i];
		if (i == length-1){
			(*(list+i))->next = 0;
		}else{
			(*(list+i))->next = (*(list+i+1));
		}
	}
	free(list);
	return root;
}



/*-------------------
current->next...size...next->(cuurent->next)...
null_flag => 1 for allow return NULL else show error
-------------------*/

int sll_concat(sl_list *current,sl_list *next,int size, int null_flag){

	if(size < 1){
		MYERR("size should be >= 1\n");
	}

	if(null_flag!=0 && null_flag != 1){
		MYERR("flag shoul be 0 or 1\n");
	}

	sl_list *end = _sll_get(next, size-1, null_flag);


	if(!end){
		if(!null_flag){
			MYERR("out of index\n");
		}else{
			return 0;
		}
	}
	_sll_concat(current,next,end);

	return 1;
}




int sll_pop(sl_list *current){
	return sll_remove(current,-1);
}




int sll_remove(sl_list *current,int index){
	sl_list *root = current;
	sl_list *next;

	if (index < 0){
		index = sll_size(current) + index;
	}

	if(index < 0){
		MYERR("out of index \n");
	}

	int i = 0;
	for (i = 1; i < index && current; i++){
		current = current->next;
	}


	if(!current){
		MYERR("out of index\n");
	}

	next = current->next;

	if(!next){
		MYERR("out of index\n");
	}



	if (index == 0){
		int temp_val = root->val;
		root->val = next->val;
		next->val = temp_val;
		return _sll_remove(current, next);
	}else{
		return _sll_remove(current, next);
	}
}



void sll_append(sl_list *current,int val){
	sll_add(current,-1,val);
}

void sll_add(sl_list *current,int index,int val){
	sl_list *root = current;
	if (index < 0){
		index = sll_size(current) + index ;
	}

	if(index < 0){
		MYERR("out of index \n");
	}

	int i = 0;
	for (i = 1; i < index && current; i++){
		current = current->next;
	}
	if(!current){
		MYERR("out of index\n");
	}

	sl_list *next = malloc(sizeof(sl_list));

	if(!next){
		MYERR("No memory to malloc\n");
	}

	next->val = val;
	next->next = 0;

	if (index == 0){
		int temp_val = root->val;
		root->val = next->val;
		next->val = temp_val;
		_sll_add(current, next);
	}else{
		_sll_add(current, next);
	}

	return;
}



int sll_size(sl_list *root){
	sl_list *current = root;
	int count = 0;
	while(current){
		current = current->next;
		count+=1;
	}
	return count;
}


void sll_retrieve(sl_list *root){
	sl_list *current = root;
	printf("[ || -> ");
	while(current){
		printf("%d -> ",current->val);
		current = current->next;
	}
	printf("NULL ]\n");
	return;
}



int sll_get(sl_list *root,int index){
	sl_list *re = _sll_get(root, index, 1);
	return re->val;
}



void sll_free(sl_list *root){
	while(!root){
		sl_list *last = root;
		root = root->next;
		free(last);
	}
	return;	
}

