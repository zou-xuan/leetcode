#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = 0;
		int column = matrix[0].size()-1;
		while (row >= 0 && column >= 0
			&&row<matrix.size()&&column<matrix[0].size()){
			if (matrix[row][column] == target){
				return true;
			}
			if (matrix[row][column] > target){
				column--;
			}
			if (matrix[row][column] < target){
				row++;
			}
		}
		return false;
	}
};