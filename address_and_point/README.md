#### Question about how point & address work:

```c
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
```



```
Before: address of *p1 0x0; address of p1 0x7ffee0447998
Before: address of *p2 0x7f883ec00350; address of p2 0x7ffee0447990
Before: address of p3 0x7ffee044798c

In function: address of *a 0x7f883ec02710; address of a 0x7ffee0447948; value: 1
In function: address of *b 0x7f883ec00350; address of b 0x7ffee0447940; value: 2
In function: address of c 0x7ffee044798c; value: 3

After: address of *p1 0x0; address of p1 0x7ffee0447998
After: address of *p2 0x7f883ec00350; address of p2 0x7ffee0447990
After: address of p3 0x7ffee044798c

address of p4: 0x7f883ec02710, value: 1
```





#### conclusion:

1. pass a address into function (&p3 == c) 

2. malloc outside(p2 == b but &p2 != &b)

3. function return point and assign it outside(p4)

   - the address of point inside of function is different from outside(&a != &p4), but (a == p4)

   ​