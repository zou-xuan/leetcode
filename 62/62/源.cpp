#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> path(m, vector<int>(n, -1));
		return getOrUpdate(m-1, n-1, path);
	}

	int getOrUpdate(int m, int n, vector<vector<int>>& path){
		if (m < 0 || n < 0) return 0;
		if (n == 0) return 1;
		if (m == 0) return 1;
		if (path[m][n] != -1){
			return path[m][n];
		}
		else{
			int result= getOrUpdate(m - 1, n, path) + getOrUpdate(m, n - 1, path);
			path[m][n] = result;
			return result;
		}
	}

};

void main(){
	Solution s;
	s.uniquePaths(2, 2);
}