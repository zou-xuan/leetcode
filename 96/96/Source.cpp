#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
public:
	int numTrees(int n) {
		int result=0;
		if (n == 0||n==1){
			return 1;
		}
		for (int i = 1; i <= n; i++){
			int left = i - 1;
			int right = n - i;
			int tmp = getNums(left)*getNums(right);
			result += tmp;
		}
		return result;

	}

	int getNums(int num){
		if (nums.find(num) != nums.end()){
			return nums[num];
		}
		else{
			int result = numTrees(num);
			nums[num] = result;
			return result;
		}
	}

private:
	unordered_map<int, int> nums;
};

void main(){
	Solution s;
	s.numTrees(2);
}