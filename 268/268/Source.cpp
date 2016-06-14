#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		vector<bool> index(nums.size() + 1, false);
		for (int num : nums){
			index[num] = true;
		}
		for (int i = 0; i < index.size() + 1; i++){
			if (!index[i]){
				return i;
			}
		}
	}
};