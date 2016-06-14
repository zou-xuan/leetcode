#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		double result = log10(n) / log10(3);
		return (result - (int)result) == 0;
	}
};