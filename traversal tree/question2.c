

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 };

int** solution_v1(struct TreeNode *current, int **result, int **columnSizes, int *returnSize, int depth){

	//if root is NULL return 
    if (current == NULL){
        return result;
    }

   	int next_depth = depth+1;
	struct TreeNode *left = current->left;
	struct TreeNode *right = current->right;

	// current depth is n then next-depth is n+1
	// assume we already in left nodes
	// returnSize should be n+1 which is same as value of next depth
	// if returnSize,the max depth, is less than next depth
	// we find a deeper level (current level)
    if (*returnSize < next_depth) {

    	//increase *returnSize
        *returnSize = next_depth;

        //increase result depth by 1 to reach current level
        result = realloc(result, (depth + 1) * sizeof(int *));
        
        // set it as NULL
        (result)[depth] = NULL;

    	//add 1 more column
        *columnSizes = realloc(*columnSizes, (depth + 1) * sizeof(int));

        //current index as 0
        (*columnSizes)[depth] = 0;
    }
    
    //expand result array at current level by 1 int
    (result)[depth] = realloc((result)[depth], ((*columnSizes)[depth] + 1) * sizeof(int));
    (result)[depth][(*columnSizes)[depth]] = current->val;
    (*columnSizes)[depth] += 1;
   		
   	// if it has left child
    if (left != NULL){
    	result = solution_v1(left,  result, columnSizes, returnSize,next_depth);
    }

    //if it has right child
    if (right != NULL){
	    result = solution_v1(right, result, columnSizes, returnSize,next_depth);
    }

    return result;
}


int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    int **result;
    result = NULL;
    *returnSize = 0;
    result = solution_v1(root, result, columnSizes, returnSize,0);
    
    return result;
}

int main(int argc, char const *argv[]){
	struct TreeNode root[7];
	root[0].val = 1;
	root[1].val = 2;
	root[2].val = 2;
	root[3].val = 4;
	root[4].val = 3;
	root[5].val = 3;
	root[6].val = 4;

	root[0].left = root+1;
	root[0].right = root+2;

	root[1].left = root+3;
	root[1].right = root+4;

	root[2].left = root+5;
	root[2].right = root+6;

	root[3].left = NULL;
	root[3].right = NULL;

	root[4].left = NULL;
	root[4].right = NULL;

	root[5].left = NULL;
	root[5].right = NULL;

	root[6].left = NULL;
	root[6].right = NULL;

	int** columnSizes;
	int* returnSize;
	int** result;
	int size;

	returnSize = malloc(sizeof(int));
	columnSizes = malloc(sizeof(int*));
	columnSizes[0] = malloc(sizeof(int));
	*returnSize = 0;

    result = levelOrder(root,columnSizes,returnSize);



	printf("[\n");
	for (int i = 0; i < *returnSize; i++){
		printf("[ ");
		size =  (*columnSizes)[i];
		for (int j = 0; j < size; j++){
			printf("%d, ", result[i][j] );
		}
		printf("]\n");
	}

	printf("]\n");

	for (int i = 0; i < *returnSize; i++){
		free(result[i]);
	}

	free(result);
	free(*columnSizes);
	free(columnSizes);
	free(returnSize);

	return 0;
}











