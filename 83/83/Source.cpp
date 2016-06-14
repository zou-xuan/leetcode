#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL||head->next==NULL){
			return head;
		}
		unordered_set<int> valueSet;
		ListNode* p = head;
		valueSet.insert(p->val);
		while (p->next != NULL){
			if (valueSet.find(p->next->val) != valueSet.end()){
				p->next = p->next->next;
			}
			else{
				valueSet.insert(p->next->val);
				p = p->next;
				
			}
		}
		return head;
	}
};