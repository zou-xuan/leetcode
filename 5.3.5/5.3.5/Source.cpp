#include<iostream>
#include"LinkedList.h"
#include"TreeNode.h"
using namespace std;

class Solution{
public:
	TreeNode* listToBST(ListNode* head){
		int len = 0;
		ListNode* p = head;
		while (p){
			len++;
			p = p->next;
		}
		return listToBST(head, 0, len - 1);
	}
private :

	TreeNode* listToBST(ListNode* &list, int start, int end){
		if (start > end){
			return nullptr;
		}
		int mid = start + (end - start) / 2;
		TreeNode* leftChild = listToBST(list, start, mid - 1);
		TreeNode* parent = new TreeNode(list->data);
		parent->left = leftChild;
		list = list->next;
		parent->right = listToBST(list, mid + 1, end);
		return parent;
	}
};

void main(){
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four= new ListNode(4);
	ListNode* five = new ListNode(5);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	Solution s;
	s.listToBST(one);
}