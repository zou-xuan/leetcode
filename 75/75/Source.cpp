#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		for (int i = 0; i <= right; i++){
			while (nums[i] == 2) swap(nums[i], nums[right--]);
			while (nums[i] == 0) swap(nums[i], nums[left++]);
		}
	}
};