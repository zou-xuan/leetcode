#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size() - 1));
	}

	int rob(vector<int>& nums, int start, int end){
		int a = 0;
		int b = 0;
		for (int i = start; i <= end; i++){
			if (i % 2 == 0){
				a = max(b, a + nums[i]);
			}
			else{
				b = max(a, b + nums[i]);
			}
		}
		return max(a, b);
	}
};