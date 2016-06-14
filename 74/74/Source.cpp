#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int left = 0;
		int n = matrix.size();
		int m = matrix[0].size();
		int right = m*n - 1;
		int mid = (right + left)/2;
		while (left<=right){
			mid = (left + right) / 2;
			int num = matrix[mid / m][mid%m];
			if (num == target){
				return true;
			}
			else if (num < target){
				left = mid + 1;
				
			}
			else{
				right = mid - 1;
			}
		}
		return false;
	}
};