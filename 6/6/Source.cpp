#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		vector<vector<char>> result(numRows, vector<char>());
		if (numRows == 1){
			return s;
		}
		for (int i = 0; i < s.length(); i++){
			char c = s[i];
			int beforeIndex = i % (2 * numRows - 2);
			int index = beforeIndex <= numRows - 1 ? beforeIndex : 2 * numRows - 2 - beforeIndex;
			result[index].push_back(c);
			
		}
		string tmp = "";
		for (int i = 0; i < numRows; i++){
			tmp += string(result[i].begin(), result[i].end());
		}
		cout << tmp << endl;
		return tmp;

	}                                                
};

void main(){
	Solution s;
	string str = s.convert("abcdefghij", 2);
}