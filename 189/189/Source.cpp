#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		vector<int> tmp(nums.end() - k , nums.end());
		tmp.insert(tmp.end(), nums.begin(), nums.end() - k );
		nums = tmp;
	}
};

void main(){
	Solution s;
	vector<int> v({ 1 });
	s.rotate(v,0);
}