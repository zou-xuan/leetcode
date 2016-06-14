#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

	}

	TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
		vector<int>& inorder, int inStart, int inEnd,unordered_map<int,int>& map){

	}
};