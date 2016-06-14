#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL){
			return new TreeNode(head->val);
		}
		ListNode* prev = NULL;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != NULL&&fast->next->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
			if (prev == NULL){
				prev = head;
			}
			else{
				prev = prev->next;
			}
		}
		TreeNode* root = new TreeNode(slow->val);
		if (prev != NULL){
			prev->next = NULL;
			root->left = sortedListToBST(head);
		}
		else{
			root->left = sortedListToBST(NULL);
		}
		
		root->right = sortedListToBST(slow->next);
		return root;
	}


};

void main(){
	Solution s;
	ListNode* head = new ListNode(1);
	ListNode* second = new ListNode(2);
	head->next = second;
	s.sortedListToBST(head);
}