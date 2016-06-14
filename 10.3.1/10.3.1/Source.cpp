#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int uniquePathWithObstacle(vector<vector<int>>& obstacle){
		const int m = obstacle.size();
		const int n = obstacle[0].size();
		this->f = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
		return dfs(obstacle, m, n);
	}

private :
	vector<vector<int>> f;

	int dfs(const vector<vector<int>>& obstacle, int x, int y){
		if (x < 1 || y < 1){
			return 0;
		}
		if (obstacle[x - 1][y - 1]){
			return 0;
		}
		if (x == 1 && y == 1) return 1;
		return getOrUpdate(obstacle, x - 1, y) + getOrUpdate(obstacle, x, y - 1);
	}

	int getOrUpdate(const vector<vector<int>>& obstacle, int x, int y){
		if (f[x][y] > 0) return f[x][y];
		else
			return f[x][y] = dfs(obstacle, x, y);
	}
};