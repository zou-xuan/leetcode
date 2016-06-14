#include<iostream>
#include<vector>
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
	int rob(TreeNode* root) {
		if (root == NULL) return 0;
		vector<int> result;
		result.push_back(0);
		vector<TreeNode*> nodes;
		nodes.push_back(root);
		rob(result, nodes,0);
		return result.back();
	}

	void rob(vector<int>& result, vector<TreeNode*>& nodes, int level){
		vector<TreeNode*> nextNodes;
		int levelSum = 0;
		for (TreeNode* p : nodes){
			if (p->left != NULL) nextNodes.push_back(p->left);
			if (p->right != NULL) nextNodes.push_back(p->right);
			levelSum += p->val;
		}
		int prevPrev = level - 2 < 0 ? 0 : result[level - 2];
		int prev = level - 1 < 0 ? 0 : result[level - 1];
		int tmp = max(levelSum + prevPrev, prev);
		result[level] = tmp;
		if (nextNodes.empty()){
			return;
		}
		rob(result, nextNodes, level + 1);

	}
};


void main(){
//	vector<TreeNode*> s;
	
//	cout << s.empty() << endl;
	Solution s;
	s.rob(new TreeNode(3));
}