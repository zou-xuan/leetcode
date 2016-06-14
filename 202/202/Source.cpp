#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		
		unordered_set<int> numSet;
		return isHappy(numSet, n);

	}

	bool isHappy(unordered_set<int>& numSet, int n){
		if (n <= 0) return false;
		if (n == 1) return true;
		else{
			if (numSet.find(n) != numSet.end()){
				return false;
			}
			else{
				numSet.insert(n);
				int newNum = 0;
				while (n != 0){
					int tmp = n % 10;
					newNum += tmp*tmp;
					n = n / 10;
				}
				return isHappy(numSet, newNum);
			}
		}
	}

	bool isPowerOfTwo(int n) {
		while (n != 0){
			if (n % 2 == 0){
				n = n / 2;
				if (n == 1)
					return true;
			}
		}
		return false;
	}

};