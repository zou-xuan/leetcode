#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int totalLength = nums.size();
		int zeroLoc = 0;
		int current = 0;
		while (zeroLoc<=totalLength-1&& current <= totalLength-1 ){
			while (nums[zeroLoc] != 0 && zeroLoc <= totalLength-1 ){
				zeroLoc++;
			}
			while (nums[current] == 0 && current <= totalLength-1 ){
				current++;
			}
				
			if (zeroLoc<=totalLength-1&&current<=totalLength-1){
				int tmp = nums[zeroLoc];
				nums[zeroLoc] = nums[current];
				nums[current] = tmp;
				

			}
			
		}
	}
};

void main(){
	Solution s;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	s.moveZeroes(v);
	cout <<"" << endl;
}