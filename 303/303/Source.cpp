#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		if (nums.size() == 0) return;
		leftSum = vector<int>(nums.size());
		rightSum = vector<int>(nums.size());
		
		for (int i = 1; i < nums.size(); i++){
			rightSum[0] += nums[i];
		}
		totalSum += nums[0]+rightSum[0];
		for (int i = 1; i < nums.size(); i++){
			leftSum[i] = nums[i - 1] + leftSum[i - 1];
			rightSum[i] = rightSum[i - 1] - nums[i ];

		}
	}

	int sumRange(int i, int j) {
		return totalSum - leftSum[i] - rightSum[j];
	}

private:
	vector<int> leftSum;
	vector<int> rightSum;
	int totalSum = 0;
};
