#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		if (!popStack.empty()){
			transferStack(popStack, pushStack);
		}
		pushStack.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (!pushStack.empty()){
			transferStack(pushStack, popStack);
		}
		popStack.pop();
	}

	// Get the front element.
	int peek(void) {
		if (!pushStack.empty()){
			transferStack(pushStack, popStack);
		}
		return popStack.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return popStack.empty() && pushStack.empty();
	}

private :
	stack<int> pushStack;
	stack<int> popStack;

	void transferStack(stack<int>& fromStack, stack<int>& toStack){
		while (!fromStack.empty()){
			int tmp = fromStack.top();
			fromStack.pop();
			toStack.push(tmp);
		}
	}
};