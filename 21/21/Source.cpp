#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* dummy=new ListNode(-1);
		ListNode* current = dummy;
		while (p != NULL&&q != NULL){
			if (p->val < q->val){
				current->next = p;
				current = p;
				p = p->next;
			}
			else if (p->val >= q->val){
				current->next = q;
				current = q;
				q = q->next;
			}
		}
		if (q == NULL){
			current->next = p;
		}
		else{
			current->next = q;
		}
		return dummy->next;
	}
};

