#include<iostream>
#include"TreeNode.h"
#include<stack>
#include<vector>

using namespace std;

vector<int> preorderTraversal(TreeNode* root){
	vector<int> result;
	stack<TreeNode*> st;
	TreeNode* p = root;
	st.push(p);
	while (!st.empty()){
		TreeNode* current = st.top();
		result.push_back(current->val);
		if (current->right != nullptr){
			st.push(current->right);
		}
		if (current->left != nullptr){
			st.push(current->left);
		}
		
	}
	return result;
}

vector<int> inorderTraversal(TreeNode* root){
	stack<TreeNode*> st;
	vector<int> result;
	TreeNode* current = root;
	st.push(current);
	while (!st.empty() || current != nullptr){
		if (current != nullptr){
			st.push(current);
			current = current->left;
		}
		else{
			TreeNode* current = st.top();
			result.push_back(current->val);
			st.pop();
			current = current->right;
		}
	}
	return result;
}

vector<int> postorder(TreeNode* root){
	stack<TreeNode*> st;
	vector<int> result;
	TreeNode* current = root;
	TreeNode* visited;
	do{
		while (current != nullptr){
			st.push(current);
			current = current->left;
		}
		visited = nullptr;
		while (!st.empty()){
			current = st.top();
			st.pop();
			if (current->right == visited){
				result.push_back(current->val);
				visited = current;
			}
			else{
				st.push(current);
				current = current->right;
				break;
			}
		}
	} while (!st.empty());
	return result;
}