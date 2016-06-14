#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int secretArr[10] = { 0 };
		int guessArr[10] = { 0 };
		int bull = 0;
		int cow = 0;
		for (int i = 0; i < secret.length(); i++){
			char s = secret[i];
			char g = guess[i];
			if (s == g){
				bull++;
			}
			secretArr[s - '0']++;
			guessArr[g - '0']++;
		}
		for (int i = 0; i < 10; i++){
			cow += min(secretArr[i], guessArr[i]);
		}
		cow = cow - bull;
		return to_string(bull) + "A" + to_string(cow) + "B";
	}
};