#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int count = 0;
		int length = nums.size();
		int start = 0;
		int end = length - 1;
		while (start <= end){
			while (nums[start] != val&&start<=end){
				start++;
			}
			while (nums[end] == val&&start<=end){
				end--;
				count++;
			}
			if (start <= end){
				nums[start] = nums[end];
				count++;
				start++;
				end--;
			}
		}
		if (length - count == 0){
			nums.clear();
		}
		return length - count;
	}
};