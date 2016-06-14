#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	int findMaxLength(string s){
		int start = 0;
		int end = 0;
		int maxLength = 0;
		int location[26];
		fill(location, location + 26, -1);
		int length = s.length();
		while (end < length){
			if (location[s[end] - 'a'] >= start){
				maxLength = max(maxLength, end - start);
				start = location[s[end] - 'a'] + 1;
				
			}
			location[s[end] - 'a'] = end;

		}
		maxLength = max(maxLength, end - start);
		return maxLength;
	}

};