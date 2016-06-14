#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		
		ListNode* p = head;
		unordered_map<int,bool> map;
		while (p != NULL){
			if (map.find(p->val) == map.end()){
				map.insert({ p->val, false });
			}
			else{
				map[p->val] = true;
			}
			p = p->next;
		}
		ListNode dummy(0);
		dummy.next = head;
		p = head;
		ListNode* prev = &dummy;
		while (p != NULL){
			if (map[p->val]){
				prev->next = p->next;
				p = p->next;
			}
			else{
				prev = prev->next;
				p = p->next;
			}
		}
		return dummy.next;
	}
};