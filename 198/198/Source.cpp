#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		return rob(nums, nums.size() - 1);
	}

private :
	map<int, int> maxMap;

	int rob(vector<int>& nums, int index){
		if (index < 0) return 0;
		if (index == 0) return nums[0];
		int indexNum = nums[index];
		return max(getOrUpdate(nums,maxMap,index-2)+indexNum,
			getOrUpdate(nums, maxMap, index - 1));
	}

	int getOrUpdate(vector<int>& nums, map<int, int>& maxMap, int index){
		if (maxMap.find(index) != maxMap.end()){
			return maxMap[index];
		}
		else{
			maxMap[index] = rob( nums, index);
			return maxMap[index];
		}
	}
};