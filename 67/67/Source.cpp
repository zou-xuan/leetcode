#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int alength = a.length();
		int blength = b.length();
		int maxLength = max(alength, blength);
		vector<char> v(maxLength);
		int index = 0;
		int carry = 0;
		while (maxLength-1-index>=0){
			
			int anum = alength - 1 - index >= 0 ? a[alength - 1 - index] - '0' : 0;
			int bnum = blength - 1 - index >= 0 ? b[blength - 1 - index] - '0' : 0;
			int num = anum + bnum + carry;
			if (num == 0 || num == 1){
				v[maxLength - 1 - index] = num+'0';
				carry = 0;
			}
			else if (num == 2||num==3){
				v[maxLength - 1 - index] = num-2+'0';
				carry = 1;
			}
			index++;

		}
		if (carry == 1){
			string result = "1" + string(v.begin(), v.end());
			return result;
		}
		else{
			return string(v.begin(), v.end());
		}
	}
};

void main(){
	Solution s;
	s.addBinary("11", "10");
}