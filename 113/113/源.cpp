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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> path;
		pathSum(sum, root, path, result);
		return result;

	}

	void pathSum(int left, TreeNode* node, vector<int>& path, vector<vector<int>>& result){
		if (node == NULL) return;
		path.push_back(node->val);
		if (node->left == NULL&&node->right==NULL&&left == node->val){
			result.push_back(path);
			
		}
		int val = node->val;
		pathSum(left - val, node->left, path, result);
		pathSum(left - val, node->right, path, result);
		path.pop_back();

	}
};