#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		int maxNum = pow(2, n)-1;
		vector<int> result;
		vector<bool> mark(n, false);
		int prev=0;
		result.push_back(0);
		mark[0] = true;
		for (int k = 1; k <= maxNum; k++){
			for (int i = 1; i <= maxNum; i++){
				if (!mark[i]){
					int tmp = prev^i;
					if (tmp == 1 || tmp % 2 == 0){
						result.push_back(i);
						mark[i] = true;
						prev = i;
					}
				}
				
			}
		}
		return result;
		
	}
};