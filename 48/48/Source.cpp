#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i <n-1- j){
					swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
				}
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i < n / 2){
					swap(matrix[i][j], matrix[n - 1 - i][j]);
				}
			}
		}

	}
};