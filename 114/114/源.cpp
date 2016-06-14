#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL) return;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		root->left = NULL;
		flatten(left);
		flatten(right);
		root->right = left;
		TreeNode* end = root;
		while (end->right != NULL) end = end->right;
		end->right = right;

	}
};

void main(){

}