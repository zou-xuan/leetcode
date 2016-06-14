#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		connect(root, NULL);
	}

	void connect(TreeLinkNode* root, TreeLinkNode* sibling){
		if (root == NULL){
			return;
		}
		root->next = sibling;
		connect(root->left, root->right);
		if (sibling != NULL){
			connect(root->right, sibling->left);
		}
		else{
			connect(root->right, NULL);
		}
	}
};