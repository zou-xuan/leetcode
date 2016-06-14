#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return heightDifference(root) >= 0;
	}

private :
	int heightDifference(TreeNode* root){
		if (root == NULL) return 0;
		int leftHeight = heightDifference(root->left);
		int rightHeight = heightDifference(root->right);
		if (leftHeight < 0 || rightHeight<0 || abs(leftHeight - rightHeight)>1){
			return -1;
		}
		return max(leftHeight, rightHeight) + 1;
	}
};