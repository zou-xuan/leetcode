#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		pushAll(root);
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* current = s.top();
		s.pop();
		pushAll(current->right);
		return current->val;
	}

private :
	stack<TreeNode*> s;

	void pushAll(TreeNode* p){
		if (p == NULL) return;
		s.push(p);
		while (p->left != NULL){
			s.push(p -> left);
			p = p->left;
		}
	}

};
