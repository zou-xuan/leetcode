#include<iostream>
#include<vector>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL){
			return;
		}
		vector<TreeLinkNode*> v;
		v.push_back(root);
		connect(v);
	}

	void connect(vector<TreeLinkNode*> v){
		if (v.empty()){
			return;
		}
		vector<TreeLinkNode*> nextLevel;
		for (int i = 0; i < v.size() - 2; i++){
			v[i]->next = v[i + i];
			nextLevel.push_back(v[i]->left);
			nextLevel.push_back(v[i]->right);
		}
		v[v.size() - 1]->next = NULL;
		nextLevel.push_back(v[v.size() - 1]->left);
		nextLevel.push_back(v[v.size() - 1]->right);
		connect(nextLevel);
	}
};