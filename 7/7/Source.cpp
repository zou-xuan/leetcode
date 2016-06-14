#include<iostream>

using namespace std; 

class Solution {
public:
	int reverse(int x) {
		int result = 0;
		bool isPos = true;
		if (x<0){
			isPos = false;
			x = -x;
		}
		int maxNum = INT_MAX;

		while (x != 0){
			if (result>maxNum / 10){
				return 0;
			}
			result *= 10;
			
			result += x % 10;
			x = x / 10;
		}
		return isPos?result:-result;
	}
};

void main(){
	Solution s;
	cout<<s.reverse(-100)<<endl;
	
}