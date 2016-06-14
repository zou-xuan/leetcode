#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		
		ListNode* smallStart = NULL;
		ListNode* largeStart = NULL;
		ListNode* smallPrev = NULL;
		ListNode* largePrev = NULL;
		ListNode* p = head;
		while (p!= NULL){
			if (p->val < x){
				if (smallStart == NULL){
					smallStart = p;
					smallPrev = p;
				}
				else{
					smallPrev->next = p;
					smallPrev = p;
				}

			}
			else{
				if (largeStart == NULL){
					largeStart = p;
					largePrev = p;
				}
				else{
					largePrev->next = p;
					largePrev = p;
				}
			}
			p = p->next;
		}
		if (smallPrev == NULL) return largeStart;
		if (largePrev == NULL) return smallStart;
		smallPrev->next = largeStart;
		largePrev->next = NULL;
		return smallStart;
		
	}
};

void main(){
	ListNode* one = new ListNode(2);
	ListNode* two = new ListNode(1);
	one->next = two;
	Solution s;
	s.partition(one,2);
}