#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root->left == NULL&&root->right == NULL) return;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		root->left = invertTree(right);
		root->right = invertTree(left);
		return root;
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL || q == NULL) return (p == NULL) && (q == NULL);
		return (p->val == q->val) && isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right);
	}
};