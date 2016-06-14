#include<iostream>
#include<algorithm>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		vector<TreeNode*> list;
		list.push_back(root);
		zigzagLevelOrder(list, 0, result);
		return result;
	}

	void zigzagLevelOrder(vector<TreeNode*>& nodeList, int level, vector<vector<int>>& result){
		if (nodeList.empty()) return;
		vector<TreeNode*> nextLevel;
		for (TreeNode* p : nodeList){
			if (p->left != NULL) nextLevel.push_back(p->left);
			if (p->right != NULL) nextLevel.push_back(p->right);
		}

		if (level % 2 != 0){
			reverse(nodeList.begin(), nodeList.end());
		}
		vector<int> tmp;
		for (TreeNode* p : nodeList){
			tmp.push_back(p->val);
		}
		result.push_back(tmp);
		zigzagLevelOrder(nextLevel, level + 1, result);
	}
};