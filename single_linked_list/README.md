How to use my single_linked_list?



```c

/*
struct _Node{
	int id; // Node id
	int val; //address 
	struct _Node *next;
};

typedef struct _Node sl_list;
*/


/*
this function return a single linked list with NULL
[ ||-> NULL ]
*/
sl_list* sll_init_empty();


/*
given a int array and size of this array to create a single linked list 
[ ||->array[0]->array[1]->...->NULL ]
*/
sl_list* sll_init( int* array, int length);

/*
concatenate two single linked list
null_flag = 1  return null when concatenate fails
null_flag = 0  exit and show error when concatenate fails
ex:
int a[3] = {1,2,3};
int b[4] = {4,5,1};
list_a = sll_init(a,2); then list_a: [||->1->2->NULL]
list_b = sll_init(b,3); then list_b: [||->4->5->1->NULL]
sll_concat(list_a,list_b,2, 1);
result:
[||->1->4->5->2->NULL]
*/
int sll_concat(sl_list *current,sl_list *next,int size, int null_flag);

/*
create a note added after current node
ex:
[||->A->B->C->D->NULL] call sll with current as A, index as 1
result:
[||->A->B->E->C->D->NULL]
*/
void sll_add(sl_list *current,int index,int val);

/*
[||->A->B->C]
result:
[||->A->B->C->D]
*/
void sll_append(sl_list *current,int val);


/*
[||->A->B->C->D] remove 2
result:
[||->A->B->D] 
*/
int sll_remove(sl_list *current,int index);

/*
[||->A->B->C->D]
results:
[||->A->B->D] 
*/
int sll_pop(sl_list *current);


/*
print the single linked list from root
*/
void sll_retrieve(sl_list *root);


/*
always call it after call sll_init() or sll_init_empty();
*/
void sll_free(sl_list *root);

/*
return size from root
*/
int sll_size(sl_list *root);

/*
return value at index of single linked list
*/
int sll_get(sl_list *root,int index);



```



