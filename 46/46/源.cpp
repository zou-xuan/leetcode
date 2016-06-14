#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		return permute(nums, 0);
	}

	vector<vector<int>> permute(vector<int>& nums, int start){
		vector<vector<int>> result;
		if (start == nums.size() - 1){
			vector<int> v;
			v.push_back(nums[start]);
			result.push_back(v);
			return result;
		}
		int current = nums[start];
		vector<vector<int>> tmp = permute(nums, start + 1);
		for (vector<int> p : tmp){
			for (int i = 0; i <= p.size(); i++){
				vector<int> pp = p;
				pp.insert(pp.begin()+i, current);
				result.push_back(pp);
			}
		}
		return result;
	}
};


void main(){
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	s.permute(v);
}