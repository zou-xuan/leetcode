#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.size() == 0){
			return digits;
		}
		int length = digits.size();
		bool carry = false;
		digits[length - 1] ++;
		if (digits[length - 1] == 10){
			carry = true;
			digits[length - 1] = 0;
		}
		for (int i = length - 2; i >= 0; i--){
			if (carry){
				digits[i]++;
				if (digits[i] != 10){
					carry = false;
				}
				else{
					digits[i] = 0;
				}
			}
		}
		if (carry){
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};