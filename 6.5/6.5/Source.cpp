#include<iostream>
#include"ListNode.h"
using namespace std;

class Solution{
public:
	ListNode* insertSort(ListNode* list){
		if (list == nullptr || list->next == nullptr){
			return list;
		}
		ListNode* slow, *fast = list;
		while (fast->next != nullptr&&fast->next->next != nullptr){
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* l2 = slow->next;
		slow->next = nullptr;
		ListNode* l1 = insertSort(list);
		ListNode* l2 = insertSort(list);
		
	}

	ListNode* mergeSortedLists(ListNode* l1, ListNode* l2){
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode dummy(-1);
		ListNode* p = &dummy;
		for (; l1 != nullptr&&l2 != nullptr; p = p->next){
			if (l1->data > l2->data){
				p->next = l2;
				l2 = l2->next;
			}
			else{
				p->next = l1;
				l1 = l1->next;
			}
		}
		p->next = l1 != nullptr ? l1 : l2;
		return dummy.next;
	}
};