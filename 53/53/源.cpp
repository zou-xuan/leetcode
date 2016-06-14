#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int tmp = 0;
		int maxNum = INT_MIN;
		for (int i = 0; i < nums.size(); i++){
			tmp = max(tmp + nums[i], nums[i]);
			maxNum = max(tmp, maxNum);
		}
	}
};