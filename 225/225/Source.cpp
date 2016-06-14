#include<iostream>
#include<queue>
using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		pushQueue.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (pushQueue.size() == 0){
			pushFromTo(popQueue, pushQueue);
			popQueue.pop();
		
		}
		else{
			pushFromTo(pushQueue, popQueue);
			pushQueue.pop();
		}
		
	}

	// Get the top element.
	int top() {
		if (pushQueue.size() == 0){
			pushFromTo(popQueue, pushQueue);
			int tmp = popQueue.front();
			popQueue.pop();
			return tmp;

		}
		else{
			pushFromTo(pushQueue, popQueue);
			int tmp = pushQueue.front();
			pushQueue.pop();
			return tmp;
		}

	}

	// Return whether the stack is empty.
	bool empty() {
		return pushQueue.empty() && popQueue.empty();
	}

private :
	queue<int> pushQueue;
	queue<int> popQueue;

	bool pushFromTo(queue<int>& fromQueue, queue<int>& toQueue){
		if (fromQueue.empty()){
			return false;
		}
		while (fromQueue.size() != 1){
			int tmp = fromQueue.front();
			fromQueue.pop();
			toQueue.push(tmp);
		}
		return true;
	}
};