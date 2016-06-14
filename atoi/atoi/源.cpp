#include<iostream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int i = 0;
		int sign = 1;
		int base = 0;
		while (str[i] == ' ') i++;
		if (str[i] == '-' || str[i] == '+'){
			sign = 1 - 2 * (str[i++] == '-');
		}
		while (str[i] >= '0'&&str[i] <= '9'){
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && (str[i] - '0' > INT_MAX % 10))){
				if (sign > 0) return INT_MAX;
				else{
					return INT_MIN;
				}
			}
			base = base * 10 + str[i++] - '0';
		}
		return base*sign;
	}
};