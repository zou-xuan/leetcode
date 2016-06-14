#include<iostream>
#include<string>
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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (root == NULL) return result;
		binaryTreePaths(to_string(root->val), root->left, result);
		binaryTreePaths(to_string(root->val), root->right, result);
		if (result.empty()){
			result.push_back(to_string(root->val));
		}
		return result;
	}

private :
	void binaryTreePaths(string s, TreeNode* current, vector<string>& v){
		if (current == NULL) return;
		if (current->left== NULL&&current->right==NULL){
			s = s + "->" + to_string(current->val);
			v.push_back(s);
		}
		else{
			s = s + "->" + to_string(current->val);
			binaryTreePaths(s, current->left, v);
			binaryTreePaths(s, current->right, v);
		}
	}
};