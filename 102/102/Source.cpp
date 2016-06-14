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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (root == NULL) return result;
		vector<TreeNode*> nodes;
		nodes.push_back(root);
		return levelOrder(result, nodes, 0);
	}

private :
	vector<vector<int>> levelOrder(vector<vector<int>>& result, vector<TreeNode*>& nodes,
		int level){
		vector<TreeNode*> nextNodes;
		for (int i = 0; i < nodes.size(); i++){
			if (nodes[i] != NULL){
				if (level + 1>result.size()){
					result.push_back(vector<int>());
				}
				nextNodes.push_back(nodes[i]->left);
				nextNodes.push_back(nodes[i]->right);
				result[level].push_back(nodes[i]->val);
			}
		}
		if (!nextNodes.empty()){
			levelOrder(result, nextNodes, ++level);
		}
		return result;
	}
};

int main(){
	Solution s;
	s.levelOrder(NULL);
}
