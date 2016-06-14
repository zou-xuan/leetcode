#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL) return head;

		ListNode* a = head;
		ListNode* even_head = a->next;
		ListNode* b = even_head;

		while (b != NULL&&b->next!=NULL){
			a->next = b->next;
			b->next = a->next->next;
			a = a->next;
			b = b->next;
		}
		a->next = even_head;
		return head;
	}
};