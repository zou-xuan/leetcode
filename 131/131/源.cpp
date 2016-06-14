#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		if (s == "") return result;
		vector<string> path;
		partition(s, 0, result, path);
		return result;
	}

	void partition(string s, int start, vector<vector<string>>& result, vector<string>& path){
		int length = s.length();
		if (start >= length){
			result.push_back(path);
			return;
		}
		for (int i = start; i < length; i++){
			if (isPara(s, start, i)){
				path.push_back(s.substr(start, i - start+1));
				partition(s, i + 1, result, path);
				path.pop_back();
			}
		}
		
	}

	bool isPara(string s, int start, int end){
		while (start < end){
			if (s[start] != s[end]){
				return false;
			}
			start++;
			end--;
		}
		return true;
	}
};