#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int totalGas = 0, totalCost = 0, tank = 0, start = 0;
		for (int i = start; i < gas.size(); i++){
			totalGas += gas[i];
			totalCost += cost[i];
			tank = tank + gas[i] - cost[i];
			if (tank < 0){
				start = i + 1;
				tank = 0;
			}
		}
		if (totalCost>totalGas) return -1;
		else return start;
	}
};