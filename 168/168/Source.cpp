#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string s;
		n = n - 1;
		while (n >= 0){
			int tmp = n % 26;
			char tmpChar = 'A' + tmp;
			s = tmpChar+s;
			n /= 26;
			n--;
		}
		return s;
	}
};

void main(){
	Solution s;
	cout << s.convertToTitle(28);
}