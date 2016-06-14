#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		
		int n = grid.size();
		int  m= grid[0].size();
		vector<vector<int>> result(n, vector<int>(m, -1));
		return minPathSum(grid, n-1, m-1,result);
	}

	int minPathSum(vector<vector<int>>& grid, int n, int m,vector<vector<int>>& result){
		if (m == 0 && n == 0){
			return grid[0][0];
		}
		if (result[n][m] != -1){
			return result[n][m];
		}
		int tmp1 = INT_MAX, tmp2 = INT_MAX;
		if (m - 1 >= 0){
			tmp1 = minPathSum(grid, n, m-1,result) + grid[n][m];
		}
		if (n - 1 >= 0){
			tmp2 = minPathSum(grid, n-1, m,result) + grid[n][m];
		}
		int s= min(tmp1,tmp2);
		result[n][m] = s;
		return s;

	}
};