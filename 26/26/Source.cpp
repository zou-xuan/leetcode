#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 1) return nums.size();
		int first = 0;
		int second = first+1;
		int length = nums.size();
		
		for (; second < length; second++){
			int firstNum = nums[first];
			int secondNum = nums[second];
			if (secondNum != firstNum){
				first++;
				nums[first] = nums[second];
			}
		}
		return first + 1;
	}
};