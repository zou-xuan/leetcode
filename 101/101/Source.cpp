#include<iostream>
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
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		else{
			return isIdentical(root->left, root->right);
		}
		
	}

private :
	bool isIdentical(TreeNode* first, TreeNode* second){
		if (first == NULL || second == NULL) return first == second;
		if (first->val != second->val){
			return false;
		}
		return isIdentical(first->left, second->right) 
			&& isIdentical(first->right, second->left);
	}
};

class SolutionNonRecursive{
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		stack<TreeNode*> s;
		if (root->left == NULL || root->right == NULL)
			return root->left == root->right;
		s.push(root->left);
		s.push(root->right);
		TreeNode* left;
		TreeNode* right;
		while (!s.empty()){
			if (s.size() % 2 != 0) return false;
			right = s.top();
			s.pop();
			left = s.top();

			s.pop();
			if (right->val != left->val) return false;
			if (left->left == NULL || right->right == NULL){
				if (left->left != right->right){
					return false;
				}
			}
			else{
				s.push(left->left);
				s.push(right->right);
			}
			if (left->right == NULL || right->left == NULL){
				if (left->right != right->left){
					return false;
				}
			}
			else{
				s.push(left->right);
				s.push(right->left);
			}

		}
		return true;
	}

};

void main(){
	TreeNode* root=new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(2);
	root->left = left;
	root->right = right;
	SolutionNonRecursive s;
	cout << s.isSymmetric(root) << endl;
}