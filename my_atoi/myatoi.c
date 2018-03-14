
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>

int myAtoi(char* str) {


  	int i = 0;
  	int element;
  	int count_of_period = 0;
  	int count = 0;
  	int neg = 0;
  	int re_array[11];
  	int max[10] ={2,1,4,7,4,8,3,6,4,7};

  	int begin_zero = 1;
  	int first = 1;

  	while((element = str[i++])!= '\0'){
  		//get first non-' 'or'0' element 
  		if(first){
  			if(element == '0' || element == ' '){
  				continue;
  			}
  			first = 0;
		  	if(element == '-'){
		  		neg = 1;
		  	}else if(element == '+'){
		  		neg = 0;
		  	}else if(element <='9' && element>'0'){
		  		re_array[count] = element-'0';
		  		count+=1;
		  		begin_zero = 0;
		  	}else{
		  		return 0;
		  	}
		  	continue;
  		}
  		
  		if (element == '.'){
  			count_of_period+=1;
	  		if(count_of_period > 1){
	  			return 0;
	  		}
	  	}else if(element <= '9' && element>= '0'){
	  		if(begin_zero && (element == '0')){
	  			continue;
	  		}else{
	  			begin_zero = 0;
	  		}

	  		if(!count_of_period){
		  		re_array[count] = element-'0';
		  		count+=1;
		  		  	//check if out range
			  	if (count > 10){
			  		return (neg? INT32_MIN:INT32_MAX );
			  	}
	  		}
	  	}else{
	  		break;
	  	}
  	}


  	int out_range = 1;
  	// check if outrange
  	if (count == 10){
  		for (int i = 0; i < 10 && out_range; i++){
  			if (max[i] < re_array[i]){
  				return (neg? INT32_MIN:INT32_MAX );
  			}else if(max[i] > re_array[i]){
  				out_range =0;
  			}
  		}
  		if(out_range){
  			if(!neg){
  				return INT32_MAX;
  			}else{
  				if(re_array[9]==8){
  					return INT32_MIN;
  				}
  			}
  		}
  	}
  	//in range
  	int re = 0;
  	neg = (neg)? -1: 1;
	for (int i = 0; i < count; i++){
		re += (neg)*re_array[i]*pow(10,count-i-1);
	}

    return re;
}

int main(int argc, char const *argv[]){
	
	char* str ="1095502006p8";
	int re = myAtoi(str);
	printf("%d\n",re );

	 //46. 48 0 57
	return 0;
}



