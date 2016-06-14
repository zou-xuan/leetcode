#include<iostream>
#include<stack>
using namespace std;

class MinStack {
private :
	stack<int> valueStack;
	stack<int> minStack;

public:
	void push(int x) {
		valueStack.push(x);
		if (getMin() >= x){
			minStack.push(x);
		}
	}

	void pop() {
		int value = valueStack.top();
		valueStack.pop();
		if (value == getMin()){
			minStack.pop();
		}
	}

	int top() {
		return valueStack.top();
	}

	int getMin() {
		if (minStack.empty()){
			return INT_MAX;
		}
		return minStack.top();
	}

	
};