#include<iostream>
#include<queue>
#include"TreeNode.h"
using namespace std;

void rightPointer(TreeNode* root){
	while (root){
		TreeNode* next = nullptr;
		TreeNode* prev = nullptr;
		for (; root; root = root->next){
			if (!next) next = root->left ? root->left : root->right;
			if (root->left){
				if (prev) prev->next = root->left;
				prev = root->left;
			}
			if (root->right){
				if (prev) prev->next = root->right;
				prev = root->right;
			}
		}
		root = next;
	}
}