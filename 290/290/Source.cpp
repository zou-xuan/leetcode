#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> strv;
		splitString(str, strv);
		if (pattern.length() != strv.size()) return false;
		unordered_map<char, string> map;
		unordered_set<string> used;
		for (int i = 0; i < pattern.length(); i++){
			char c = pattern[i];
			if (map.find(c)!= map.end()){
				string suppose = map[c];
				if (suppose.compare(strv[i]) != 0){
					return false;
				}
			}
			else{
				if (used.find(strv[i]) != used.end()){
					return false;
				}
				else{
					map[c] = strv[i];
					used.insert(strv[i]);
				}
			}
		}
		return true;
	}

private :
	void splitString(const string& str, vector<string>& v){
		string::size_type i = 0;
		string::size_type j = str.find(' ');
		if (j == string::npos){
			v.push_back(str.substr(i, str.length()));
		}
		while (j != string::npos){
			v.push_back(str.substr(i, j-i));
			i = ++j;
			j = str.find(' ', j);
			if (j == string::npos){
				v.push_back(str.substr(i, str.length()));
			}
		}

	}
};

void main(){
	Solution s;
	s.wordPattern("e", "adfa");
}