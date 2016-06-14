#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	vector<vector<int>> getPerm(vector<int>& num){

	}

private :
	void getPerm(vector<int>& num, int index, 
		vector<int>& path,vector<vector<int>>& result){
		if (index == num.size() - 1){
			result.push_back(path);
			return;
		}
		int item = num[index];

	}
};