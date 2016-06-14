#include<iostream>
using namespace std;

class Solution{
public:
	string minWindow(string S, string T){
		if (S.size() < T.size()){
			return "";
		}
		const int maxChar = 256;
		int appeared_count[maxChar];
		int expected_count[maxChar];
		fill(appeared_count, appeared_count + maxChar, 0);
		fill(expected_count, expected_count + maxChar, 0);
		for (size_t i = 0; i < T.size; i++){
			expected_count[T[i]]++;
		}
		int minWidth = INT_MAX;
		int start = 0;
		int end = 0;
		int appeared = 0;
		for (size_t end = 0; end < S.size; end++){
			if (expected_count[S[end]]>0){
				appeared_count[S[end]]++;
				if (appeared_count[S[end]] <= expected_count[S[end]]){
					appeared++;
				}
			}
			if (appeared == T.size()){
				while (appeared_count[S[start]] > expected_count[S[start]] ||
					expected_count[S[start]] == 0){
					appeared_count[S[start]]--;
					start++;
				}
			
			}
		}
	}
};