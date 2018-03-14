

[back to main](./../../../)



#### Question 

1. Given an integer **m**, check if **m** is a power of **2**.



#### Solution:

```c
/*
assume m = 2^n
m		=>	..0100...0
(m-1)	=>	..0011...1
m&(m-1) =>	..0000...0
*/
int solution_1(int n){
	return (n>0) && ((n&(n-1))==0);
}

```





