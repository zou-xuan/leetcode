#include<iostream>
using namespace std;

class KMP{
public:
	char* strStr(const char* haystack, const char* needle){
		int pos = kmp(haystack, needle);
		if (pos == -1) return nullptr;
		else return (char*)haystack + pos;
	}

private:
	static void compute_prefix(const char* pattern, int next[]){
		int i;
		int j = -1;
		const int m = strlen(pattern);
		next[0] = j;

		for (i = 1; i < m; i++){
			while (j>-1 && pattern[j + 1] != pattern[i]) j = next[j];
			if (pattern[i] == pattern[j + 1]) j++;
			next[i] = j;
		}
	}
};