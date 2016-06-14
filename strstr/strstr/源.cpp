#include<iostream>
using namespace std;

class Solution{
public :
	const char* strStr(const char* haystack, const char*  needle){
		char startChar = *needle;
		const char* search = needle;
		const char* p = haystack;
		const char* result = NULL;
		while (*p != '\0'){
			if (*p != *search){
				p++;
			}
			else{
				result = p;
				while (*p == *search){
					p++;
					search++;
					if (*search == '\0'){
						return result;
					}
				}
				p = ++result;
				search = needle;
			}
		}
		return nullptr;
	}
};

void main(){
	Solution s;
	char haystack[] = "abcdefghijk";
	char needle[] = "cdej";
	const char* result = s.strStr(haystack, needle);
	if (result != NULL){
		cout <<result << endl;
	}
	
	
}