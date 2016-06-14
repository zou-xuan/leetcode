#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		else{
			ListNode* slow = head;
			ListNode* fast = head;
			while (fast->next != NULL&&fast->next->next!=NULL){
				slow = slow->next;
				fast = fast->next->next;
			}
			ListNode* newhead = reverseList(slow->next);
			ListNode* p = head;
			while (newhead != NULL){
				if (newhead->val != p->val){
					return false;
				}
				newhead = newhead->next;
				p = p->next;
			}
			return true;
		}
	}

private :
	ListNode* reverseList(ListNode* head){
		ListNode* next = head->next;
		ListNode* before = NULL;
		ListNode* current = head;
		while (next != NULL){
			current->next = before;
			before = current;
			current = next;
			next = current->next;
		}
		current->next = before;
		ListNode* newHead = current;
		return current;
	}
};