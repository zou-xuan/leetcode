#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		permuteUnique(nums, 0, nums.size(), result);
		return result;
	}

	void permuteUnique(vector<int>& nums, int start, int end, 
		vector<vector<int>>& result){
		if (start == end - 1){
			result.push_back(nums);
			return;
		}
		for (int i = start; i < end; i++){
			if (i != start&&nums[start] == nums[i]){
				continue;
			}
			swap(nums[start], nums[i]);
			permuteUnique(nums, start + 1, end, result);
			swap(nums[start], nums[i]);
		}
	}
};