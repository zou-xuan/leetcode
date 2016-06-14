#include<iostream>
using namespace std;

bool wild_match(const char* s, const char* p){
	if (*p == '\0') return *s == '\0';
	if (*(p + 1) != '*'){
		if (*p == *s || (*p == '?'&&*s != '\0')){
			return wild_match(s + 1, p + 1);
		}
		else{
			return false;
		}
	}
	else{
		if (*p == *s || (*p == '?'&&*s!='\0')){
			const char* mark = s;
			s++;
			if (*(p + 2) == '\0') return true;
			while (*(p + 2) != *s&&*s != '\0'){
				s++;
			}
			if (*s == '\0') return false;
			else{
				return wild_match(s, p + 2);
			}
		}
		return false;
	}
}

void main(){
	char string[] = "aabb";
	char pattern[] = "a*b";
	cout << wild_match(string, pattern) << endl;
}