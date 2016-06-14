#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* p = head;
		ListNode* newHead = head->next;
		while (p->next != NULL){
			if (p->next->next == NULL){
				ListNode* next = p->next;
				p->next = NULL;
				next->next = p;
				break;
			}
			else{
				ListNode* next = p->next;
				ListNode* newNext = p->next->next->next;
				if (newNext == NULL){
					newNext = p->next->next;
				}
				ListNode* loop = p -> next->next;
				p->next = newNext;
				next->next = p;
				p = loop;
			}

		}
		return newHead;
	}
};