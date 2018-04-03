

question is from leetcode



```
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
```





solution:

```c
long foo(long mydivisor,long mydividend){

	long current_int=0;
	long count = 1;

	// init current_int
	current_int = mydivisor;

	// find a count which dividend in interval [divisor*2^(count-1), divisor*2^count)
	while(current_int <= mydividend){
		count <<= 1;  
		current_int <<= 1;
	}
	count >>= 1;
	current_int >>=1;


	// recursively call self with new dividend as reminder of (mydividend - current_int)
	if (mydivisor <= mydividend - current_int){
		count += foo(mydivisor,mydividend - current_int);
	}

	return count;
}

int divide(int dividend, int divisor) {


	long mydividend = (long)dividend;
	long mydivisor = (long)divisor;

	long count = 0;
	int sign = (mydivisor<0 )^(mydividend<0); //binary operation 

	// absolute value of dividend and divisor
	mydividend = mydividend < 0? -mydividend:mydividend;
	mydivisor = mydivisor<0 ? -mydivisor: mydivisor;

	count = foo(mydivisor, mydividend);
	
	// add sign to count
	count = sign ? (-count): count;

	// check if overflow, if it is, return INT_MAX
	return (count < INT_MIN ||count > INT_MAX) ? INT_MAX: count;
}

```

