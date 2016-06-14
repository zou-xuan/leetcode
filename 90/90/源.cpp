#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> v;
		result.push_back(v);
		map<int, int> numMap;
		for (int num : nums){
			if (numMap.find(num) != numMap.end()){
				int count = numMap[num];
				numMap[num] = ++count;
			}
			else{
				numMap.insert({ num, 1 });
			}
		}
		for (map<int, int>::iterator it = numMap.begin(); it != numMap.end();it++){
			vector<vector<int>> subResult = result;
			for (vector<int> v : subResult){
				vector<int> tmp = v;
				for (int j = 0; j < it->second; j++){
					tmp.push_back(it->first);
					result.push_back(tmp);
				}
			}
		}
		return result;
	}
};

void main(){
	Solution s;
	vector<int> v({1,3,5,2,4, 2, 2, 3, 4 });
	s.subsetsWithDup(v);
}