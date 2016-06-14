#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int size = nums.size();
		int index = 0;
		int n = 0;
		for (int i = size-1; i >=1; i--){
			if (nums[i - 1] < nums[i]){
				index = i;
				break;
			}
		}
		if (index == 0){
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = size - 1; i >= index; i--){
			if (nums[i]>nums[index - 1]){
				n = i;
				break;
			}
		}
		swap(nums[n], nums[index-1]);
		reverse(nums.begin() + index, nums.end());

	}
};