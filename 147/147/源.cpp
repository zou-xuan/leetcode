#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode dummy(INT_MIN);
		
		ListNode* p = head;
		while (p != NULL){
			ListNode* start = &dummy;
			while (start->next != NULL&&start->next->val < p->val){
				start = start->next;
			}
			ListNode* tmp = start->next;
			ListNode* nextP = p->next;
			start->next = p;
			p->next = tmp;
			p = nextP;
		}
		return dummy.next;
	}
};