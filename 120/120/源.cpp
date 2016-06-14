#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		int level = triangle.size();
		int n = triangle[level - 1].size();
		vector<int> totalSum(triangle.back());
		for (int i = level - 2; i >= 0; i--){
			int index = 0;
			while (index < triangle[i].size()){
				totalSum[index] = min(totalSum[index], totalSum[index + 1])
					+ triangle[i][index];
				index++;
			}
		}
		return totalSum[0];
	}
};