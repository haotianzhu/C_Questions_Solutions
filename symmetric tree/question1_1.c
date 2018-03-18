
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 };
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int solution_v1(struct TreeNode *left, struct TreeNode *right){

	// first check current left == right
    if (left == NULL && right == NULL){
        return 1;
    }
    
	if (left->val != right->val){
		return 0;
	}
    

    int r1,r2;
    
    if(left->left != NULL && right->right != NULL){
        r1 = solution_v1( (left->left), (right->right));
    }else if (left->left == NULL && right->right == NULL){
        r1 = 1;
    }else{
        return 0;
    }

   	if (left == right){
        //root 
        return r1;
    }
    
    
    if(right->left != NULL && left->right != NULL){
        r2 = solution_v1( (left->right), (right->left));
    }else if (right->left == NULL && left->right == NULL){
        r2 = 1;
    }else{
        return 0;
    }


    return r1&&r2;   
}

int isSymmetric(struct TreeNode* root) {
    return solution_v1(root,root);
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
	int r = isSymmetric(root);
	printf("%d\n",r );

	return 0;
}