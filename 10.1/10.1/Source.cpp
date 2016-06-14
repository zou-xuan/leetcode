#include<iostream>
#include<vector>
using namespace std;

class Solution{
public :
	vector<vector<string>> partition(string s){

	}

	void DFS(string& s, vector<string>& path, vector<vector<string>>& result,
		int start){
		if (start == s.size()){
			result.push_back(path);
			return;
		}
		for (int i = start; i < s.size(); i++){
			if (isPalindome(s, start, i)){
				path.push_back(s.substr(start, i - start + 1));
				DFS(s, path, result, i + 1);
				path.pop_back();
			}
		}

	}

private :
	bool isPalindome(string s, int start, int end){
		while (start < end&&s[start] == s[end]){
			start++;
			end--;
		}
		return start <= end;
	}
};