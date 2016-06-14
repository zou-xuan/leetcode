#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string* buff = new string[numRows];
		int index = 0;
		int length = s.length();
		while (index < length){
			for (int i = 0; i < numRows&&index < length; i++){
				buff[i]+=s[index++];
			}
			for (int i = numRows - 2; i >= 1 && index < length; i--){
				buff[i] += s[index++];
			}
		}
		for (int i = 1; i < numRows; i++){
			buff[0] += buff[i];
		}
		string result = buff[0];
		delete[] buff;
		return result;
	}
};


void main(){
	Solution s;
	cout<<s.convert("abcdefghijklmnopqrstuv", 4);
}