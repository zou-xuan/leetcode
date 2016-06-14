#include<iostream>
#include<vector>
#include"TreeNode.h"
using namespace std;

class Solution{
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum){
		vector<vector<int>> result;
		vector<int> current;
		pathSum(root, sum, current, result);
		return result;
	}

private :
	void pathSum(TreeNode* root, int sum, vector<int> current,
		vector<vector<int>>& result){
		if (root == nullptr){
			return;
		}
		current.push_back(root->val);
		if (root->left == nullptr&&root->right == nullptr){
			if (sum == root->val){
				result.push_back(current);
			}
		}
		else{
			pathSum(root->left, sum - root->val, current, result);
			pathSum(root->right, sum - root->val, current, result);
		}
	//	current.pop_back();

	}
};


void main(){	
	TreeNode* root = new TreeNode(5);
	TreeNode* one = new TreeNode(4);
	TreeNode* two = new TreeNode(8);
	TreeNode* three = new TreeNode(11);
	TreeNode* four = new TreeNode(13);
	TreeNode* five = new TreeNode(4);
	TreeNode* six = new TreeNode(7);
	TreeNode* seven = new TreeNode(2);
	TreeNode* eight = new TreeNode(5);
	TreeNode* nine= new TreeNode(1);
	root->left = one;
	root->right = one;
	one->left = three;
	two->left = four;
	two->right = five;
	three->left = six;
	three->right = seven;
	five->left = eight;
	five->right = nine;
	Solution s;
	vector<vector<int>> result = s.pathSum(root, 22);
	cout << "" << endl;
}