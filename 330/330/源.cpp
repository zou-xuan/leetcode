#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		int miss = 1;
		int i = 0;
		int add = 0;
		int size = nums.size();
		while (miss <= n){
			if (i < size && nums[i] <= miss){
				miss += nums[i++];
			}
			else{
				miss += miss;
				add++;
			}
		}
		return add;
	}
};