#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> result;
		if (root == NULL) return result;
		q.push(root);
		while (!q.empty()){
			int size = q.size();
			result.push_back(q.back()->val);
			for (int i = 0; i < size; i++){
				TreeNode* current = q.front();
				q.pop();
				if (current->left != NULL) q.push(current->left);
				if (current->right != NULL) q.push(current->right);
			}
		}
		return result;
	}
};