#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		vector<char> s(n * 2);
		getPar(result, n, n, s, 0);
		return result;
	}

	void getPar(vector<string>& result, int leftRemain, int rightRemain, vector<char> s,
		int count){
		if (leftRemain == 0 && rightRemain == 0){
			string tmp(s.begin(), s.end());
			result.push_back(tmp);
		}
		if (leftRemain > 0){
			s[count]='(';
			getPar(result, leftRemain - 1, rightRemain, s, count+1);
		}
		if (rightRemain > leftRemain){
			s[count] = ')';
			getPar(result, leftRemain, rightRemain - 1, s, count+1);
		}
		

	}
};

void main(){
	Solution s;
	s.generateParenthesis(2);
}