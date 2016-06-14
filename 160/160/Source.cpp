#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* pA = headA;
		ListNode* pB = headB;
		int countA = 0;
		int countB = 0;
		if (pA == NULL || pB == NULL) return NULL;
		while (pA->next != NULL){
			pA = pA->next;
			countA++;
		}
		while (pB->next != NULL){
			pB = pB->next;
			countB++;
		}
		if (pA != pB) return NULL;
		else{
			pA = headA;
			pB = headB;
			int difference = countA - countB;
			if (difference < 0){
				difference = -difference;
				for (int i = 0; i < difference; i++){
					pB = pB->next;
				}
			}
			else{
				for (int i = 0; i < difference; i++){
					pA = pA->next;
				}
			}
			while (pA != pB){
				pA = pA->next;
				pB = pB->next;
			}
			return pA;
		}
	}
};