//Date:2015-11-29
//Author:lidengke

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		if(NULL == root)
			return _vecStr;
		
		_ss.str("");
		_ss << root->val;
		string s = _ss.str();
				
		if(NULL == root->left && NULL == root->right) {
			_vecStr.push_back(s);
			return _vecStr;	
		}

		if(NULL != root->left) {
			addNextNode(s, root->left);
		}

		if(NULL != root->right) {
			addNextNode(s, root->right);
		}

		return _vecStr;
	}
private:
	void addNextNode(string str, TreeNode* node) {
		_ss.str("");
		_ss << str << "->" << node->val;
		string s = _ss.str();
	
		if(NULL == node->left && NULL == node->right) {
			_vecStr.push_back(s);
			return ;
		}

		if(NULL != node->left) {
			addNextNode(s, node->left);
		}

		if(NULL != node->right) {
			addNextNode(s, node->right);
		}

	}
private:
	vector<string> 	_vecStr;
	stringstream	_ss;
};


int main(int argc, char const *argv[])
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

	vector<string> vecStr = Solution().binaryTreePaths(&six);

	copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, "\n"));
	cout << endl;

	return 0;
}