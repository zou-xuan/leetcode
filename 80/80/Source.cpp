#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) return nums.size();
		int slow = 1;
		int fast = 1;
		bool hasDup = false;
		int prev = nums[0];
		while (fast < nums.size()){
			if (nums[fast] == prev&&hasDup){
				while (fast<nums.size()&&nums[fast] == prev) fast++;
				if (fast == nums.size()-1) return slow;
				nums[slow] = nums[fast];
				prev = nums[fast];
				slow++;
				fast++;
				hasDup = false;
			}
			else if (nums[fast] == prev&&!hasDup){
				hasDup = true;
				nums[slow] = nums[fast];
				prev = nums[fast];
				fast++;
				slow++;
			}
			else{
				nums[slow] = nums[fast];
				prev = nums[fast];
				slow++;
				fast++;
				
				hasDup = false;

			}
			
		}
		return slow ;
	}
};


void main(){
	Solution s;
	vector<int> v({ 1, 1,1});
	s.removeDuplicates(v);
}