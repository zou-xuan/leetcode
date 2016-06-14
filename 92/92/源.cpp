#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		ListNode dummy(0);
		dummy.next = head;
		ListNode* start = &dummy;
		ListNode* p = head;
		int count = 1;
		while (count < m){
			start = start->next;
			p = p->next;
			count++;
		}
		ListNode * current = p->next;
		while (count < n){
			ListNode* tmp = current->next;
			current->next = p;
			p = current;
			current = tmp; 
			count++;
		}
		start->next->next = current;
		start->next = p;
		return dummy.next;
	}
};