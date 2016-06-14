#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		if (nums.size() == 0) return result;
		int start = nums[0];
		int former = nums[0];
		for (int i = 1; i < nums.size(); i++){
			if (nums[i] == former + 1){
				former = nums[i];
			}
			else{
				string s;
				if (start == former){
					s = to_string(start);
				}
				else{
					s = to_string(start) + "->" + to_string(former);
				}
				result.push_back(s);
				start = nums[i];
				former = nums[i];
			}
		}
		string s;
		if (start == former){
			s =to_string(start);
		}
		else{
			s = to_string(start) + "->" + to_string(former);
		}
		result.push_back(s);

		return result;
	}
};


void main(){
	Solution s;
	vector<int> v({0,1,2,6});
	s.summaryRanges(v);
	
}