#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> result(nums.size(),0);
		for (int i = 0, tmp = 1; i < nums.size(); i++){
			result[i] = tmp;
			tmp *= nums[i];
		}
		for (int i = nums.size() - 1, tmp = 1; i >= 0; i--){
			result[i] *= tmp;
			tmp *= nums[i];
		}
		return result;
	}
};