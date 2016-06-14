#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int start = 0;
		int end = nums.size() - 1;
		k = nums.size() - k;
		while (start < end){
			int j = partition(nums, start, end);
			if (j < k){
				start = j+1;
			}
			else if (j>k){
				end = j-1;
			}
			else{
				break;
			}

		}
		return nums[k];
	}

	int partition(vector<int>& nums,int start,int end){
		int left = start;
		int right = end+1;
		while (left < right){
			while (left < end&&nums[++left] < nums[start]);
			while (right>start&&nums[start]<nums[--right]);
			if (left >= right) break;
			swap(nums[left], nums[right]);
		}
		swap(nums[start], nums[right]);
		return right;
	}
};

void main(){
	vector<int> v({3,3,3,3,3,3,3});
	Solution s;
	s.partition(v,0,v.size()-1);
	
}