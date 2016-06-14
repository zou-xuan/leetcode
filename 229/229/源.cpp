#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> result;
		if (nums.empty()) return result;
		int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 0;
		for (int n : nums){
			if (n == candidate1){
				count1++;
			}
			else if (n == candidate2){
				count2++;
			}
			else if (count1 == 0){
				candidate1 = n;
				count1 = 1;
			}
			else if (count2 == 0){
				candidate2 = n;
				count2 = 1;
			}
			else{
				count1--;
				count2--;
			}
		}
		count1 = 0, count2 = 0;
		for (int n : nums){
			if (n == candidate1) count1++;
			if (n == candidate2) count2++;
		}
		if (count1 > nums.size() / 3) result.push_back(candidate1);

		if (count2 > nums.size() / 3&&candidate1!=candidate2) result.push_back(candidate2);
		return result;
	}
};