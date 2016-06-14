#include<iostream>
#include<algorithm>
#include"TreeNode.h"
using namespace std;

class Solution{
public :
	bool isBalanced(TreeNode* root){
		return balancedHeight(root) >= 0;
	}

	int balancedHeight(TreeNode* root){
		if (root == nullptr) return 0;
		else{
			int left = balancedHeight(root->left);
			int right = balancedHeight(root->right);
			if (left == -1 || right == -1||abs(left-right)>1) return -1;
			else{
				return max(left, right) + 1;
			}
		}
	}
};