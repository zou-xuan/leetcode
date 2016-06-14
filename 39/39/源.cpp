#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> path;
		getSum(candidates, 0,target, result, path);
		return result;
	}

	void getSum(vector<int>& c, int startIndex, int target, 
		vector<vector<int>>& result,vector<int>& path){
		if (c.empty()||startIndex>=c.size()||target < c[startIndex]){
			return;
		}
		else if (target == c[startIndex]){
			path.push_back(c[startIndex]);
			result.push_back(path);
			path.pop_back();
		}
		else{
			path.push_back(c[startIndex]);
			getSum(c, startIndex, target - c[startIndex], result, path);
			path.pop_back();
			getSum(c, startIndex + 1, target, result, path);
		}
	}
};

void main(){
	vector<int> c({ 2, 3, 6, 7 });
	Solution s;
	s.combinationSum(c, 7);
}