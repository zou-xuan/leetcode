#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		int left = 0;
		int right = n-1;
		int top = 0;
		int bottom = n-1;
		int count = 1;
		while (count<=n*n){
			for (int i = left; i <= right; i++){
				matrix[top][i] = count++;

			}
			top++;
			for (int i = top; i <= bottom; i++){
				matrix[i][right] = count++;

			}
			right--;
			for (int i = right; i >= left; i--){
				matrix[bottom][i] = count++;

			}
			bottom--;
			for (int i = bottom; i >= top; i--){
				matrix[i][left] = count++;
			}
			left++;
		}
		return matrix;
	}
};