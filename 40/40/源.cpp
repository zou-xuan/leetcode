#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> path;
		if (candidates.empty()) return result;
		sort(candidates.begin(), candidates.end());
		combination(candidates, 0, target, result, path);
		return result;

	}

	void combination(vector<int>& candidates,int start, int target, vector<vector<int>>& result,
		vector<int>& path){

		if (target == 0){
			result.push_back(path);
			return;
		}
		if (candidates[start] > target || start > candidates.size()){
			return;
		}
		
		
		for (int i = start; i < candidates.size() && candidates[i] <= target; i++){
			int current = candidates[i];
			path.push_back(current);
			combination(candidates, i + 1, target - current, result, path);
			path.pop_back();
		}
	}
};

void main(){
	Solution s;
	vector<int> candi({ 1,2,3 });
	s.combinationSum2(candi, 3);
}