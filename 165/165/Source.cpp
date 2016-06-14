#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<string> stringVector1;
		vector<string> stringVector2;
		stringstream firstStream(version1);
		stringstream secondStream(version2);
		string item;
		while (getline(firstStream, item, '.')){
			stringVector1.push_back(item);
		}
		while (getline(secondStream, item, '.')){
			stringVector2.push_back(item);
		}
		int length = max(stringVector1.size(), stringVector2.size());
		for (int i = 0; i < length; i++){
			
			int firstNum = i<stringVector1.size()?stoi(stringVector1[i]):0;
			int secondNum = i<stringVector2.size() ? stoi(stringVector2[i]) : 0;
			if (firstNum>secondNum){
				return 1;
			}
			else if (firstNum < secondNum){
				return -1;
			}
			
		}
		return 0;
	}
};