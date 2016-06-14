#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int> v;
		helper(k, n, 1,v, result);
		return result;
	}

	void helper(int leftCount,int target,int startNum,
		vector<int>& v,vector<vector<int>>& result) {
		
		if (leftCount == 0 && target == 0){
			result.push_back(v);
			return;
		}
		if (leftCount<0 || startNum>target){
			return;
		}
		else{
			for (int i = startNum; i <= 9; i++){
				v.push_back(i);
				helper(leftCount - 1, target - i, i + 1, v, result);
				v.pop_back();
			}
		}
		

	}
};