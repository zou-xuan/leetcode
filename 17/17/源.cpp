#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits == "") return ans;
		vector<string> map({ "0", "1", "abc", "def", "ghi", "jkl",
			"mno", "pqrs", "tuv", "wxyz" });
		ans.push_back("");
		for (int i = 0; i < digits.length(); i++){
			int x = digits[i]-'0';
			while (ans[0].length() == i){
				string s =ans[0];
				ans.erase(ans.begin() + 0);
				vector<char> tmp(map[x].begin(), map[x].end());
				for (char c : tmp){
					ans.push_back(s + c);
				}
			}

		}
		return ans;
	}

	
};