#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> nodeStack;
		vector<int> result;
		if (root == NULL) return result;
		result.push_back(root->val);
		if (root->right!= NULL){
			nodeStack.push(root->right);
		}
		if (root->left != NULL){
			nodeStack.push(root->left);
		}
		while (!nodeStack.empty()){
			TreeNode* current = nodeStack.top();
			nodeStack.pop();
			result.push_back(current->val);
			if (current->right != NULL){
				nodeStack.push(current->right);
			}
			if (current->left != NULL){
				nodeStack.push(current->left);
			}

		}
		return result;
	}
};