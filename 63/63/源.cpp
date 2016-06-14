#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int row = obstacleGrid.size();
		int column = obstacleGrid[0].size();
		vector<int> path(column, 0);
		path[0] = 1;
		for (int i = 0; i < row; i++){
			for (int j = 0; j < column; j++){
				if (obstacleGrid[i][j] == 1){
					path[j] = 0;
				}
				else if(j>0){
					path[j] += path[j - 1];
				}
			}
		}
		return path[column - 1];
	}

};