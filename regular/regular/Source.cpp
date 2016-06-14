#include<iostream>
using namespace std;

bool isMatch_sample(const char* s, const char * p){
	if (*p == '\0'){
		return *s == '\0';
	}

	if (*(p + 1) != '*'){
		if (*p == *s || (*p == '.'&&*s != '\0')){
			return isMatch_sample(s + 1, p + 1);
		}
		else{
			return false;
		}
	}
	else{
		while (*p == *s || (*p == '.'&&*s != '\0')){
			if (isMatch_sample(s, p + 2)){
				return true;
			}
			s++;
		}
		return isMatch_sample(s, p + 2);
	}
}

void main(){
	char string[]= "aab";
	char pattern[] = "c*a*b";
	cout << isMatch_sample(string, pattern)<<endl;
}