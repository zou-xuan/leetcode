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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		bool isLeftFather = isFather(root->left, p) && isFather(root->left, q);
		bool isRightFather = isFather(root->right, p) && isFather(root->right, q);
		if (isLeftFather){
			return lowestCommonAncestor(root->left, p, q);
		}
		else if (isRightFather){
			return lowestCommonAncestor(root->right, p, q);
		}
		else{
			return root;
		}
	}

	bool isFather(TreeNode* root, TreeNode* p){
		if (root == NULL) return false;
		if (root == p) return true;
		return isFather(root->left, p) || isFather(root->right, p);
	}
};