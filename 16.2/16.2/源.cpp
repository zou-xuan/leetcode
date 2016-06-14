#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int minDiff = INT_MAX;
		int res = 0;
		for (int i = 0; i <= nums.size() - 3; i++){
			int start = i + 1;
			int end = nums.size()-1;
			while (start < end){
				int sum = nums[i] + nums[start] + nums[end];
				int diff = sum - target;
				if (diff == 0) return target;
				if (abs(diff) < minDiff){
					minDiff = abs(diff);
					res = sum;
				}
				diff < 0 ? start++ : end--;
			}
		}
		return res;
	}
};