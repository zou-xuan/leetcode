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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int, int> map;
		for (int i = 0; i < inorder.size(); i++){
			map.insert({ inorder[i], i });
		}
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, 
			postorder.size() - 1,map);

	}

	TreeNode* buildTree(vector<int>& inorder,int inStart,int inEnd, 
		vector<int>& postorder,int postStart,int postEnd,unordered_map<int,int>& map) {
		if (inStart > inEnd || postStart > postEnd) return NULL;
		int rootVal = postorder[postEnd];
		int leftEnd = 0;
		int rightStart = 0;
		int index = map[rootVal];
		leftEnd = index - 1;
		rightStart = index + 1;
		TreeNode* root = new TreeNode(rootVal);
		root->left = buildTree(inorder, inStart, leftEnd, postorder, postStart, 
			postStart+leftEnd-inStart,map);
		root->right = buildTree(inorder, rightStart, inEnd, postorder, 
			postStart+leftEnd-inStart+ 1, postEnd - 1,map);
		return root;
	}
};

void main(){
	Solution s;
	vector<int> in({ 1, 3, 2 });
	vector<int> post({ 3, 2, 1 });
	s.buildTree(in, post);
}