//Date:2015-11-28
//Author:lidengke

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(NULL == root){
    		return NULL;
    	} 
    	TreeNode* tmp = root->left;
    	root->left = root->right;
    	root->right = tmp;

    	invertTree(root->left);
    	invertTree(root->right);

    	return root;
    }
};

int main(int argc, char const *argv[])
{
	
	return 0;
}