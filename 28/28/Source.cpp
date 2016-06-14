#include<iostream>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int hayLength = haystack.length();
		int needleLength = needle.length();
		if ( needleLength == 0) return 0;
		int index = 0;
		while (index <= hayLength - needleLength ){
			int start = index;
			int second = 0;
			while (haystack[start] == needle[second]&&second<needleLength){
				start++;
				second++;
			}
			if (second == needleLength){
				return index;
			}
			else{
				index++;
				
			}
		}
		return -1;
	}
};