all: sll

test: sll
	gcc test.c -o test single_link_list.o
sll: single_link_list.h single_link_list.c
	gcc single_link_list.c -c

clear:
	rm *o