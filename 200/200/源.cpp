#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) return 0;
		int row = grid.size();
		int column = grid[0].size();
		int count = 0;
		for (int i = 0; i < column; i++){
			for (int j = 0; j < row; j++){
				if (grid[i][j]=='1'){
					DFS(grid, i, j, row, column);
					count++;
				}
			}
		}
		return count;
	}

	void DFS(vector<vector<char>>& grid, int i, int j,int row,int column){
		if (i < 0 || j < 0 || i >= row || j >= column || grid[i][j] == '0'){
			return;
		}
		grid[i][j] = '0';
		DFS(grid, i - 1, j, row, column);
		DFS(grid, i +1, j, row, column);
		DFS(grid, i , j-1, row, column);
		DFS(grid, i, j+1, row, column);
	}
};

void main(){
	Solution s;
	vector<char> v();
	s.numIslands()
}