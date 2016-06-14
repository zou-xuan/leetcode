#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int size = citations.size();
		vector<int> indexVector(size + 1, 0);
		for (int c : citations){
			if (c > size){
				indexVector[size]++;
			}
			else{
				indexVector[c]++;
			}
		}
		int res = 0;
		for (int i = indexVector.size() - 1; i >= 0; i--){
			res += indexVector[i];
			if (res >= i) return i;
		}
		return 0;
	}
};