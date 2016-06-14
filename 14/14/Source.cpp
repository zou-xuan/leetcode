#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		string pre = strs[0];
		for (int i = 1; i < strs.size(); i++){
			while (strs[i].find(pre) != 0){
				pre = pre.substr(0, pre.length() - 1);
			}
		}
		return pre;
	}
};