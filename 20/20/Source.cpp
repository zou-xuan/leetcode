#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '(' || s[i] == '{' || s[i] == '['){
				stack.push(s[i]);
			}
			else{
				char pair = ' ';
				switch (s[i])
				{
				case ')':
					pair = '(';
					break;
				case '}':
					pair = '{';
					break;
				case ']':
					pair = '[';
					break;
				default:
					break;
				}
				if (stack.top() != pair){
					return false;
				}
				else{
					stack.pop();
				}
			}
		}
		if (stack.empty()){
			return true;
		}
		else{
			return false;
		}

	}
};