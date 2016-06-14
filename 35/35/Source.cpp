#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			int tmp = nums[mid];
			if (target == tmp){
				return mid;
			}
			else if (target < tmp){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		return left;
	}
};