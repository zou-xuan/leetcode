#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int start = 0;
		int end = nums.size() - 1;
		while (true){
			int pos = partition(nums, start, end);
			if (pos > k - 1) end = pos - 1;
			else if (pos < k - 1) start = pos + 1;
			else return nums[pos];
		}
	}

	int partition(vector<int>& nums, int start, int end){
		int pivot = nums[start];
		int left = start + 1;
		int right = end;
		while (left <= right){
			if (nums[left]<pivot&&nums[right]>pivot){
				swap(nums[left++], nums[right--]);
			}
			if (nums[left] >= pivot) left++;
			if (nums[right] <= pivot) right--;
		}
		swap(nums[right], nums[start]);
		return right;
	}
};