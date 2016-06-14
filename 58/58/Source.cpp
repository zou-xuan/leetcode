#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		int beforeLength = 0;
		for (int i = 0; i < s.length(); i++){
			if (s[i] != ' '){
				length++;
			}
			else if((i==0||s[i-1]!=' ')&&s[i]==' '){
				beforeLength = length;
				length = 0;
			}
		}
		return length == 0 ? beforeLength : length;
	}
};