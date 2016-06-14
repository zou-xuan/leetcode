#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		bool isNegetive = false;
		if (n == 0||x==1) return 1;
		if (x == -1){
			if (n % 2 == 0) return 1;
			else return -1;
		}
		if (n == INT_MIN) return 0;
		
		if (n < 0){
			isNegetive = true;
			n = -n;
		}
		double result = 0;
		
		if (n == 1) result= x;
		if (n % 2 == 0){
		    result= myPow(x*x, n / 2);
		}
		else{
			result= myPow(x*x, n / 2)*x;
		}
		return isNegetive ? 1 / result : result;
	}
};