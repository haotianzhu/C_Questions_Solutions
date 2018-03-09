This question is from chapter 1.8 in book "Beauty of Programming"



[back to main](./../../../)



#### Question 

Assume there is a building with **n** number of  floors and **m** number of people going to different floors(may some of them go to same floor). An elevator only stops at **x **th floor. After elevator reaches **x** th floor , people have to leave and reach their floor via stairs. How to find a optimal **x** which minimize the total number of floors that people need to walk through stairs ? How about an elevator can stops at k different floors ?











#### Solution:

```c
/*-------------------

algorithm:
	three variables
	1. p1 tracks all poins below such level
	2. p2 tracks all points in such level
	3. p3 tracks all points above such level

	from level A to A+1, we only need calcualate the total distance's change
	assume level A the distance is d[A] 
	then level A+1, distance is  d[A] - p1 + p2 + p3

	total run time O(n)  => retrieve all level once
	total space need O(n) => store an array to contain points in each level

further improve:
	we can find the min level contains poins and max level contains points
	let down_boundary = min level contains points
	let up_boundary = max level contains points
	we start at down_boundary level, finding total distance, and end at up_boundary
        
-------------------*/

int solution_1(int n,int m,int k, int* p_points);

```

```c
/*-------------------
algorithm:
	for each order in C(n,k):
		find min distance
	runtime O( C(n,k)*n )
	space cost O(n)
	
	OR 

	use iteration to handle this qurstion 

	while(min distance changes):
		for each k:
			for each level in list [retrieve all levels]:
				for p in [retrieve all points[m]]:
					for each k in [retrieve results] // results variable stores k levels 
						get min_distance
					get sum(min_distance)
				check(if distance)

	run time O((m*n)^2) consider k is small constant
	space cost O(n)
-------------------*/ 

int solution_2(int n,int m,int k, int* p_points);

```

