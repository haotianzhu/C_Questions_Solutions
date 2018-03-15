

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>


#define MYREGEXPERR(...) do { \
    printf ("@ %s (%d): ", __FILE__, __LINE__); \
    printf (__VA_ARGS__); \
    exit(EXIT_FAILURE);\
} while (0)





int _reg_exp_convert(char a_char,char type){
	switch(type){
		case('d'):
			if(a_char<='9' && a_char >= '0'){
				return 1;
			}
			return 0;
		case('s'):
			if((a_char<='z' && a_char>='a' )||(a_char<='Z' && a_char>='A')){
				return 1;
			}
			return 0;
		default:
			return a_char;
	}
}

int _find_bracket(char* start){
	int i =0;
	char ch;
	while( (ch=start[i++])!='\0' && ch!=']' );

	if(ch == ']'){
		return i;
	}else{
		return 0;
	}
}


int _convert_rect_bracket(char *start, int end){
	/*need use binary tree*/
	int i = 0;
	return 1;
}

int simple_reg_exp(char* string, char* reg_exp_string){
	int i = 0, j =0;
	int last_i = -1;
	char first,second;
	int skip_min = 0, skip_max= 0,skip_num = 0;
	int skip_mode = 0;
	int next_second;
	int not_slash =1;
	int in_rannge = 1;



	while((first = string[i]) != '\0'  && (second = reg_exp_string[j]) != '\0'  ){

		if(second == '.'){
			skip_max = (skip_max<INT32_MAX ? skip_max+1:INT32_MAX); 
			skip_min = (skip_min<INT32_MAX ? skip_min+1:INT32_MAX);
			j+=1;
			continue;
		}else if(second == '?'){
			skip_max = (skip_max<INT32_MAX ? skip_max+1:INT32_MAX); 
			j+=1;
			continue;
		}else if(second == '*'){
			skip_max = INT32_MAX;
			j+=1;
			continue;
		}else if(second == '+'){
			skip_max = INT32_MAX;
			skip_min = (skip_min<INT32_MAX ? skip_min+1:INT32_MAX);
			j+=1;
			continue;
		}else if(second == '/' && not_slash){
			if( (next_second = reg_exp_string[j+1]) != '\0'){
				next_second = _reg_exp_convert(first, next_second);
				if (next_second > 1){
					if (next_second == '/'){
						not_slash = 0;
					}else{
						MYREGEXPERR("only allow /s and /d and // ");
					}
				}else if(!next_second){
				 	// not match
				 	i++;
				 	continue;
				}else{
					second = first;	
					j++;
				}

			}else{
				MYREGEXPERR("something error");
			}
		}else if(second == '['){
			int end_bracket = _find_bracket(reg_exp_string+j);
			if (!end_bracket){
				MYREGEXPERR("can't pair bracket [..] ");
			}

			/*handle [ ]*/
			//find match
			// if not show error
			// if yes convert legal range 
			// if match keep going else 
		}


		/*need handle {} and []*/


		if (((i-1)-last_i)<skip_min ){
			i++;
		}else if (((i-1)-last_i)>skip_max){
			return 0;
		}else{
			if(first == second){
				not_slash = 1;
				skip_min = 0;
				skip_max = 0;
				last_i = i;
				i++;
				j++;
			}else{
				i++;
			}
		}

	}


	if(!first && !second){
		return 1;
	}else if(!second){
		int count = 0;
		while((first = string[i]) != '\0'){
			count+=1;
			i++;
		}
		if( count < skip_min || count > skip_max){
			return 0;
		}else{
			return 1;
		}
	}else{

		while((second = reg_exp_string[j++]) != '\0'){
			if (second != '*' && second != '?'){
				return 0;
			}
		}
		return 1;
	}

}

int main(int argc, char const *argv[]){
	char* a = " a/b";
	char* b = " a/s*";
	int re = simple_reg_exp(a, b);
	printf("%d\n",re);
	return 0;
}