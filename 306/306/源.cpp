#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isAdditiveNumber(string num) {
		for (int i = 1; i <= num.size() / 2; i++){
			for (int j = 1; j <= (num.size() - i)/2; j++){
				if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))){
					return true;
				}
			}
		}
		return false;
	}

	bool check(string first, string second, string num){
		if ((first.size()>1&&first[0] == '0') || (second.size()>1&&second[0] == '0')){
			return false;
		}
		string sum = add(first, second);
		if (num == sum) return true;
		if (num.size() < sum.size() || num.substr(0, sum.size()) != sum) return false;
		else{
			return check(second, sum, num.substr(sum.size()));
		}
	}

	string add(string first, string second){
		int firstIndex = first.size() - 1;
		int secondIndex = second.size() - 1;
		vector<char> result;
		int carry = 0;
		while (firstIndex >= 0 || secondIndex >= 0){
			int firstNum = 0, secondNum = 0;
			
			if (firstIndex >= 0){
				firstNum = first[firstIndex] - '0';
				firstIndex--;
			}
			if (secondIndex >= 0){
				secondNum = second[secondIndex] - '0';
				secondIndex--;
			}
			int sum = firstNum + secondNum + carry;
			if (sum >= 10){
				sum -= 10;
				carry = 1;
			}
			else carry = 0;
			char c = sum + '0';
			result.insert(result.begin(), c);
		}
		if (carry == 1) result.insert(result.begin(), '1');
		string s(result.begin(), result.end());
		return s;
	}
};

void main(){
	Solution s;
	s.isAdditiveNumber("1123");
}