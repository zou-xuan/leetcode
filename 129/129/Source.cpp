#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		if (root == NULL) return 0;
		else{
			string s = "";
			return getSum(root,s);
		}
	}

	int getSum(TreeNode* node,string path){
		char c = node->val + '0';	
		if (node->left == NULL&&node->right == NULL){
			path = path + c;
			int result = stoi(path);
			return result;
		}
		int result = 0;
		if (node->left != NULL){
			result += getSum(node->left, path + c);
		}
		if (node->right != NULL){
			result += getSum(node->right, path + c);
		}
		return result;
	}
};