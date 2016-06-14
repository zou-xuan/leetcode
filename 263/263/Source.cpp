#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		unordered_map<int,bool> uglyMap;
		if (num <= 0){
			return false;
		}
		if (num == 1 || num == 2 || num == 3 || num == 5){
			return true;
		}
		else{
			bool d2 = false, d3 = false, d5 = false;
			if (num % 2 == 0){
				d2 = getOrUpdate(uglyMap,num / 2);
			}
			if (num % 3 == 0){
				d3 = getOrUpdate(uglyMap, num / 3);
			}
			if (num % 5 == 0){
				d5 = getOrUpdate(uglyMap, num / 5);
			}
			return d2 || d3 || d5;
		}
	}

private :
	bool getOrUpdate(unordered_map<int, bool>& uglyMap, int num){
		if (uglyMap.find(num) != uglyMap.end())
			return uglyMap[num];
		else{
			bool result = isUgly(num);
			uglyMap[num] = result;
			return result;
		}
	}
};