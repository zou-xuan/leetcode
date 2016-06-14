#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), tolower);
		int left = 0;
		int right = s.length() - 1;
		while (left < right){
			while ((s[left] < 'a' || s[left]>'z')&&
				(s[left]<'0'||s[left]>'9') && left < right){
				left++;
			}
			while ((s[right] < 'a' || s[right]>'z') && 
				(s[right]<'0' || s[right]>'9') && left < right){
				right--;
			}
			if (left<right&&s[left] != s[right]){
				return false;
			}
			else{
				left++;
				right--;
			}

		}
		return true;
	}
};

void main(){
	Solution s;
	cout<<s.isPalindrome("");
}