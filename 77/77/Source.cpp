#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		if (n < 1 && k != 0) return result;
		if (k == 0){
			vector<int> v;
			result.push_back(v);
			return result;
		}
		result = combine(n - 1, k - 1);
		for (int i = 0; i < result.size(); i++){
			result[i].push_back(n);
		}
		vector<vector<int>> noN = combine(n - 1, k);
		result.insert(result.end(), noN.begin(), noN.end());
		return result;
	}
};

void main(){
	Solution s;
	s.combine(1, 1);
}