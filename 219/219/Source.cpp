#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> numSet;
		int num = min(k+1, (int)nums.size());
		for (int i = 0; i < num; i++){
			if (numSet.find(nums[i]) != numSet.end()){
				return true;
			}
			else{
				numSet.insert(nums[i]);
			}
		}
		while (num < nums.size()){
			numSet.erase(nums[num - k-1]);
			if (numSet.find(nums[num]) != numSet.end()){
				return true;
			}
			else{
				numSet.insert(nums[num]);
				num++;
			}
		}
		return false;

	}
};