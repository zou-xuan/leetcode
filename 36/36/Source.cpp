#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool user_row[BOARD_SIZE][BOARD_SIZE] = { false};
		bool user_column[BOARD_SIZE][BOARD_SIZE] = { false };
		bool user_square[BOARD_SIZE][BOARD_SIZE] = { false };
		for (int i = 0; i < BOARD_SIZE; i++){
			for (int j = 0; j < BOARD_SIZE; j++){
				if (board[i][j] != '.'){
					int num = board[i][j] - '1';
					int k = i / 3 * 3 + j / 3;
					if (user_row[i][num] || user_column[j][num] ||
						user_square[k][num]){
						return false;
					}
					else{
						user_row[i][num] = true;
						user_column[j][num] = true;
						user_square[k][num] = true;
					}
				}
				
			}
		}
		return true;
	}

private :
	 static const int BOARD_SIZE = 9;

};