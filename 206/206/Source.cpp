#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL||head->next==NULL) return head;
		ListNode* prev = NULL;
		ListNode* current = head;
		ListNode* next = head->next;
		while (current != NULL){
			current->next = prev;
			prev = current;
			current = next;
			if (current == NULL) break;

			next = next->next;

		}
		return prev;
	}
};