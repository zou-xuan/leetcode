#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(INT_MAX);
		dummy.next = head;
		ListNode* p = &dummy;
		while (p->next != NULL){
			if (p->next->val == val){
				p->next = p->next->next;
			}
			else{
				p = p->next;
			}
		}
		return dummy.next;


	}
};