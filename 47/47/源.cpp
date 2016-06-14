#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		unordered_map<int, int> map;
		for (int n : nums){
			if (map.find(n) != map.end()){
				map[n]++;
			}
			else{
				map.insert({ n, 1 });
			}
		}
		vector<vector<int>> result;
		vector<int> path;
		permuteUnique(map, path, result, nums.size());
		return result;

	}

	void  permuteUnique(unordered_map<int, int>& map, vector<int>& path, 
		vector<vector<int>>& result,int n){
		if (path.size() == n){
			result.push_back(path);
			return;
		}
		for (auto it = map.begin(); it != map.end(); it++){
			int count = 0;
			for (int i = 0; i < path.size(); i++){
				if (it->first == path[i]){
					count++;
				}
			}
			if (count < it->second){
				path.push_back(it->first);
				permuteUnique(map, path, result, n);
				path.pop_back();
			}
		}

	}
};

void main(){
	Solution s;
	vector<int> v({ 1, 2 });
	s.permuteUnique(v);
}