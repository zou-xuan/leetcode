#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minPri =INT_MAX;
		int maxProfit = 0;
		for (int i = 0; i < prices.size(); i++){
			minPri = min(minPri, prices[i]);
			maxProfit = max(prices[i] - minPri, maxProfit);
		}
		return maxProfit;
	}
};