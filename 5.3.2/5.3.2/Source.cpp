#include<iostream>
#include<vector>
#include"TreeNode.h"
using namespace std;

class Solution{
public :
	vector<TreeNode*> getBinTree(int n){
		vector<TreeNode*> result;
		for (int i = 1; i <=n; i++){
			vector<TreeNode*> nodes = getBinTree(1, i, n);
			cout << nodes.size() << endl;
			result.insert(end(result), begin(nodes), end(nodes));
		}
		return result;
	}

private :
	vector<TreeNode*> getBinTree(int start,int mid,int end){
		vector<TreeNode*> v;
		vector<TreeNode*> right;
		vector<TreeNode*> left;
		
		if (start > end){
			v.push_back(nullptr);
			return v;
		}
		for (int i = mid + 1; i <= end; i++){
			right = getBinTree(mid+1,i,end);
		}
		for (int i = start; i <= mid - 1; i++){
			left = getBinTree(start, i, mid - 1);
		}
	
		for (auto rightNode : right){
			for (auto leftNode : left){
				TreeNode* root = new TreeNode(mid);
				root->left = leftNode;
				root->right = rightNode;
				v.push_back(root);
			}
		}
		cout << v.size() << endl;
		return v;
		
	}
};

void main(){
	Solution s;
	vector<TreeNode*> result = s.getBinTree(3);
	cout << result.size() << endl;
}