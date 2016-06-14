#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string before = "1";
		string result = "";
		for (int i = 0; i < n-1; i++){
			char c = before[0];
			int count = 0;
			for (int j = 0; j < before.length(); j++){
				if (before[j] == c){
					count++;
				}
				else{
					result += to_string(count) + c;
					c = before[j];
					count = 1;
				}
			}
			result =result+  to_string(count) + c;
			before = result;
			result = "";
		}
		return before;
	}
};

void main(){
	Solution s;
	s.countAndSay(4);
}