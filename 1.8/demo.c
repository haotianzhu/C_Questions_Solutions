
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

int solution_1(int n,int m, int k, int* p_points);
int solution_2(int n,int m,int k, int* p_points);


/*-------------------
input arguments:
./demo [n] [m] [k] [seed]
-------------------*/
int main(int argc, char const *argv[]){

    if (argc != 5){
        perror("./demo [n] [m] [k] [seed]\n");
        return -1;
    }
    
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int k = atoi(argv[3]);
    long seed = atol(argv[4]);
    //init random
    srand(seed);

    //random get choices
    int points[m];
    for (int i = 0; i < m; points[i++] = rand()%n );
    for (int i = 0; i < m; i++ ){
        printf("number %d wants to go to level %d\n",i,points[i]);
    }



    // solution_1 only result as k = 1
    printf("\nsolution 1:\n");
    solution_1(n,m,k,points);
    printf("\nsolution 2:\n");
    solution_2(n,m,k,points);



    return 0;
}



/*-------------------
find a level where sum of distance between all points and this level is minimum

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
int solution_1(int n,int m,int k, int* p_points){
    int array[n];
    for (int i = 0; i < n; array[i++] = 0); // init array

    // assume we stop at 0 level => sum(p in points)
   	int points_in = 0;
    int points_below = 0;
    int points_above = 0;
    int min_length = 0;
	int target_level = 0;

	// init information space cost(n)
    for (int i = 0; i < m; i++){
    	array[p_points[i]] += 1;
    	min_length += p_points[i];
    	if (p_points[i] == 0){
    		points_in += 1;
    	}else{
    		points_above += 1;
    	}
    }	


    // assume we changes level by increasing 1, check if it decrease min_length
    for (int i = 1; i < n; i++){
    	// after increase by 1, move last points_in into points_below
    	// move # of points in this level from points_above
    	// into points_in
    	points_below += points_in;
    	points_in = 0;
    	points_in += array[i];
    	points_above -= array[i];


    	if (points_below < (points_in+points_above)){
    		min_length += (points_below - (points_in+points_above));
    		target_level = i;
    	}

    }

    printf("stop at level: %d , total length:%d\n",target_level,min_length);

    return 1;
}

/*-------------------
find k levels where total distance is minimum (each point will reach the closest level)
	
algorithm:
	for each order in C(n,k):
		find min distance
	
	or 

	use iteration to handle this qurstion 

	while(min distance changes):
		for each k:
			for each level in list [retrieve all levels]:
				for p in [retrieve all points[m]]:
					for each k in [retrieve results] // results variable stores k levels (stop level)
						get min_distance
					get sum(min_distance)
				check(if distance)

	run time O((m*n)^2) consider k is small constant
	
space cost O(n)


-------------------*/
int solution_2(int n,int m,int k, int* p_points){


    int results[k];
	for (int i = 0; i < k; i++){
		results[i] = 0;
	}

	
    // assume we stop at 0 level => sum(p in points)
    int min_distance = 1;
	// init information space cost(n)
    for (int i = 0; i < m; i++){
    	min_distance += p_points[i];
    }	

    int different = 1;
    int total_distance;
    int temp_l;
    while(different){
    	different = 0;
    	for (int i = 0; i < k; i++){
    		// move first k and its interval
    		for (int l = 0; l < n; l++){
    			//for each level
    			total_distance = 0;
    			temp_l = results[i];
    			results[i] = l;

    			for (int j = 0; j < m ; j++){
    				// find min distance
    				int min_d = n+1; // large enough value
    				for(int r = 0; r < k; r++){
    					// for each results[r]
    					if ( abs(results[r] - p_points[j])< min_d){
    						min_d = abs(results[r] - p_points[j]);
    					}
    				}
    				total_distance += min_d;
    			}
    			if (total_distance < min_distance){
    				different = 1;
    				min_distance = total_distance;
    				total_distance = 0;
    			}else{
    				results[i] = temp_l;
    			}
    		}
    	}
    }

    for (int i = 0; i < k; i++){
    	 printf("k: %d  stop at level: %d\n",i,results[i]);
    }
    printf("total length: %d\n",min_distance );

	return 1;
}

