#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		for (int i = 1; i < prices.size(); i++){
			int tmp = prices[i] - prices[i - 1];
			if (tmp>0){
				result += tmp;
			}
		}
		return result;
	}
};
