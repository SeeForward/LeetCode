//Date:2015-11-24
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(1) {
        	if(NULL == root)
        		return NULL;

        	if(root->val == p->val || root->val == q->val)
        		return root;

	      	if(p->val < root->val) {
	        	if(q->val < root->val)
	        		root = root->left;
	        	else
	        		return root;
	        } else {
	        	if(q->val > root->val)
	        		root = root->right;
	        	else
	        		return root;
	        }
	    }
    }
};

void print(TreeNode* head) {

}




int main(int argc, char* argv[])
{
	TreeNode zero(0);
	TreeNode two(2);
	TreeNode three(3);
	TreeNode four(4);
	TreeNode five(5);
	TreeNode six(6);
	TreeNode seven(7);
	TreeNode eight(8);
	TreeNode nine(9);

	six.left = &two;
	six.right = &eight;

	two.left = &zero;
	two.right = &four;

	four.left = &three;
	four.right = &five;

	eight.left = &seven;
	eight.right = &nine;


	cout << Solution().lowestCommonAncestor(&six, &two, &four) ->val << endl;
	return 0;
}
