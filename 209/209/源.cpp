#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty()) return 0;
		int  minLength = nums.size()+1, start = 0, 
			end = 0, tmp = nums[start];
		while (end < nums.size()){
			while (tmp < s&&end<nums.size()){
				end++;
				tmp += nums[end];
			}
			int gap = end - start + 1;
			if (gap < minLength){
				minLength = gap;
			}
			while (tmp>=s&&start<=end){
				
				tmp -= nums[start];
				start++;
			}
		}
		return minLength == nums.size() + 1 ? 0: minLength;
	}
};

void main(){
	Solution s;
	vector<int> v;
	s.minSubArrayLen(100, v);
}