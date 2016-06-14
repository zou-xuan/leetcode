#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> s(rowIndex + 1);
		s[0] = 1;
		for (int i = 1; i <= rowIndex; i++){
			for (int j = i; j >= 1; j--){
				s[j] += s[j - 1];
			}
		}
		return s;

	}
};