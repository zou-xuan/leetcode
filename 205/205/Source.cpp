#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length()) return false;
		unordered_map<char, char> map;
		unordered_set<char> set;
		for (int i = 0; i < s.length(); i++){
			char schar = s[i];
			char tchar = t[i];
			if (map.find(schar) != map.end()){
				if (map[schar] != tchar){
					return false;
				}
			}
			else{
				if (set.find(tchar) != set.end()){
					return false;
				}
				else{
					map[schar] = tchar;
					set.insert(tchar);
				}
			}
		}
		return true;
	}
};