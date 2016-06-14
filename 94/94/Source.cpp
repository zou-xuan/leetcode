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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> nodeStack;
		TreeNode* p = root;

		while (!nodeStack.empty() || p != NULL){
			if (p != NULL){
				nodeStack.push(p);
				p = p->left;
			}
			else{
				p = nodeStack.top();
				nodeStack.pop();
				result.push_back(p->val);
				p = p->right;
			}
		}
		return result; 

	}
};