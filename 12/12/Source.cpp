#include<iostream>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string result = "";
		while (num > 0){
			int tmp = num % 10;
			num = num / 10;
			char c = tmp + '0';
			result = c + result;
		}
		return result;
	}
};