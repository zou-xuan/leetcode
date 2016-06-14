#include<iostream>
#include<algorithm>
#include"TreeNode.h"
using namespace std;

class Solution{
public:
	int minDepth(TreeNode* root){
		if (root == nullptr)
			return 0;
		else{
			int leftDepth = minDepth(root->left);
			int rightDepth = minDepth(root->right);
			int minDepth = min(leftDepth, rightDepth);
			return 1 + minDepth;
		}
	}

};