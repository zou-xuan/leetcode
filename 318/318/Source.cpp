#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class StringCompare{
public:
	bool operator()(const string& lhs, const string& rhs){
		return lhs.length() > rhs.length();
	}
};


class Solution {
public:
	int maxProduct(vector<string>& words) {
		StringCompare sc;
		sort(words.begin(), words.end(), sc);
		int result = 0;
		vector<int> masks(words.size(), 0);
		for (int i = 0; i < words.size(); i++){
			for (int j = 0; j < words[i].length(); j++){
				masks[i] |= 1 << (words[i][j] - 'a');
			}
		}
		for (int i = 0; i < words.size(); i++){
			if (words[i].length()*words[i].length() < result) continue;
			for (int j = i + 1; j < words.size(); j++){
				if ((masks[i] & masks[j]) == 0){
					result = max(result, (int)(words[i].length()*words[j].length()));
					break;
				}
			}
		}
		return result;
	}
};


void main(){
	vector<string> words;
	words.push_back("abcw");
	words.push_back("baz");
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("xtfn");
	words.push_back("abcdef");
	Solution s;
	s.maxProduct(words);
}