#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.empty()){
			return result;
		}
		sort(nums.begin(), nums.end());
		int end = nums[nums.size() - 1];
		nums.pop_back();
		helper(result, nums, end);
		return result;
	}

	void helper(vector<vector<int>>& result, vector<int>& nums, int endNum){
		if (nums.empty()){
			vector<int> v;
			result.push_back(v);
			v.push_back(endNum);
			result.push_back(v);
			
		}
		else{
			int end = nums[nums.size() - 1];
			nums.pop_back();
			helper(result, nums, end);
			vector<vector<int>> tmp(result.begin(),result.end());
			for (vector<int> v : tmp){
				v.push_back(endNum);
				result.push_back(v);
			}
		}	
	}
};

void main(){
	Solution s;
	vector<int> nums({ 1, 2, 3 });
	s.subsets(nums);
}