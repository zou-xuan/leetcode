#include<algorithm>
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
	int minDepth(TreeNode* root) {
		if (root == NULL) return 0;
		return getDepth(root, 1);
	}

	int getDepth(TreeNode* root, int depth){
		if (root->left == NULL&&root->right == NULL){
			
			return depth;
		}
		else{
			if (depth >= minDep){
				return minDep;
			}
			else{
				int left = INT_MAX;
				int right = INT_MAX;
				if (root->left != NULL){
					left = getDepth(root->left, depth + 1) ;
				}
				if (root->right != NULL){
					right = getDepth(root->right, depth + 1) ;
				}
				
				minDep= left > right ?  right : left;
				return minDep;
			}
		}
	}

private :
	int minDep = INT_MAX;

	static int minDepth(const TreeNode* root, bool hasbrother){
		if (!root) return hasbrother ? INT_MAX : 0;
		return 1 + min(minDepth(root->left, root->right != NULL), minDepth(root->right,
			root->left != NULL));
	}
};