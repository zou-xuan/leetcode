#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int diff = 0;
		for (int num : nums){
			diff ^= num;
		}
		diff &= -diff;
		vector<int> rets = { 0, 0 };
		for (int num : nums){
			if ((num&diff) == 0){
				rets[0] ^= num;
			}
			else{
				rets[1] ^= num;
			}
		}
		return rets;
	}
};