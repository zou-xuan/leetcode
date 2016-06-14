#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL){
			return NULL;
		}
		ListNode* fast = head->next->next;
		ListNode* slow = head->next;
		while (fast != NULL&&fast->next != NULL){
			if (fast == slow){
				slow = head;
				while (slow != fast){
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
			fast = fast->next->next;
			slow = slow->next;

		}
		return NULL;
	}
};