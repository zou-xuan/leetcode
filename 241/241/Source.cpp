#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		int index = 0;
		vector<int> result;
		vector<int> numVector;
		vector<char> operatorVector;
		int start = 0;
		while (index < input.length()){
			if (input[index] == '-' || input[index] == '+' || input[index] == '*'){
				string left = input.substr(start, index - start);
				int leftNum = stoi(left);
				numVector.push_back(leftNum);
				operatorVector.push_back(input[index]);
				index++;
				start = index;		
			}
			else{
				index++;
			}
		}
		string last = input.substr(start, index - start);
		numVector.push_back(stoi(last));
		compute(result, numVector, operatorVector);
		return result;
	}

	void compute(vector<int>& result, vector<int>& numVector, vector<char>& operatorVector){
		if (operatorVector.size() == 1){
			result.push_back(calculate(numVector[0], numVector[1], operatorVector[0]));
			return;
		}
		else{
			for (int i = 0; i < operatorVector.size(); i++){
				int left = numVector[i];
				int right = numVector[i + 1];
				char c = operatorVector[i];
				int res = calculate(left, right,c);
				numVector.erase(numVector.begin() + i);
				numVector.erase(numVector.begin() + i + 1);
				numVector.insert(numVector.begin() + i, res);
				operatorVector.erase(operatorVector.begin() + i);
				compute(result, numVector, operatorVector);
				operatorVector.insert(operatorVector.begin() + i, c);
				numVector.erase(numVector.begin() + i);
				numVector.insert(numVector.begin() + i,left);
				numVector.insert(numVector.begin() + i + 1,right);
			}
		}

	}

	int calculate(int left, int right, char op){
		switch (op)
		{
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left*right;
		default:
			break;
		}
		return 0;
	}


};