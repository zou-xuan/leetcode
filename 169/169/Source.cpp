#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int count = 1;
		int majorindex = 0;
		for (int i = 0; i < nums.size(); i++){
			nums[majorindex] == nums[i] ? count++ : count--;
			if (count == 0){
				majorindex = i;
				count = 1;
			}
		}
		return nums[majorindex];
	}
};