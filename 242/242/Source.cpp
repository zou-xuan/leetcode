#include<iostream>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		int charset[256] = {};
		for (int i = 0; i < s.length(); i++){
			charset[s[i]]++;
		}
		for (int i = 0; i < t.length(); i++){
			charset[t[i]]--;
			if (charset[t[i]] < 0){
				return false;
			}
		}
		return true;
	}
};