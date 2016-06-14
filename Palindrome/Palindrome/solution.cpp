#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution{
public:
	bool isPalindrome(string s){
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while (left < right){
			while (!::isalnum(*left)) ++left;
			while ( !::isalnum(*right)) --right;
			if (*left != *right) return false;
			else{
				left++;
				right--;
			}
		}
		return true;
	}
};

void main() {
	Solution s;
	bool result=s.isPalindrome("abbc....=dc,ba");
	cout << result << endl;
}