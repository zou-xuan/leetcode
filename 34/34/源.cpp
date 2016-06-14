#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int start = 0;
		int end = nums.size() - 1;
		int mid = (start - end) / 2;
		while (start <= end){
			if (nums[mid] < target){
				start = mid + 1;
			}
			else if (nums[mid]>target){
				end = mid - 1;
			}
			else{

			}
		}
	}
};