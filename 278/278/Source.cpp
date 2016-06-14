#include<iostream>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		long left = 0;
		long right = n - 1;
		while (right - left > 1){
			long mid = (left + right) / 2;
			if (!isBadVersion(mid+1)){
				left = mid;
			}
			else{
				right = mid;
			}
		}
		if (isBadVersion(left+1)){
			return left+1;
		}
		else{
			return right + 1;
		}

	}
};