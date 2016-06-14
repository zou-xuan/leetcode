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
		bool isParentofBoth = isParent(root, p) && isParent(root, q);
		bool isLeftParent = isParent(root->left, p) && isParent(root->left, q);
		bool isRightParent = isParent(root->right, p) && isParent(root->right, q);
		if (isParentofBoth && (!isLeftParent) && (!isRightParent)){
			return root;
		}
		else if (isLeftParent){
			return lowestCommonAncestor(root->left, p, q);
		}
		else
			return lowestCommonAncestor(root->right, p, q);
	}

private :
	bool isParent(TreeNode* parent, TreeNode* child){
		if (parent == child){
			return true;

		}
		if (parent == NULL)
			return false;
		return isParent(parent->left,child) || isParent(parent->right,child);
	}
};