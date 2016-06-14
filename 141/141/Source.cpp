#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL) return false;
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast != NULL&&fast != slow){
			fast = fast->next;
			if (fast == NULL){
				break;
			}
			fast = fast->next;
			slow = slow->next;
		}
		if (fast == NULL){
			return false;
		}
		return true;
	}
};