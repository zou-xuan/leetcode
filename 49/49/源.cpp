#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		if (strs.empty()) return result;
		unordered_map<string, vector<string>> stringMap;
		for (string s : strs){
			vector<char> charVector(s.begin(),s.end());
			sort(charVector.begin(), charVector.end());
			string newStr(charVector.begin(),charVector.end());
			if (stringMap.find(newStr) != stringMap.end()){
				stringMap[newStr].push_back(s);
			}
			else{
				vector<string> ss;
				ss.push_back(s);
				stringMap.insert({ newStr, ss });
			}
		}
		for (auto iter = stringMap.begin(); iter != stringMap.end(); iter++){
			vector<string> v = iter->second;
			sort(v.begin(),v.end());
			result.push_back(v);

		}
		return result;
	}
};