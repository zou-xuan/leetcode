#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		map<int, bool> canWin;
		if (n == 1 || n == 2 || n == 3){
			return true;
		}
		else{
			bool result = getOrUpdate(canWin, n);
		}
	}

private :
	bool getOrUpdate(map<int, bool>& canWin, int n){
		if (canWin.find(n) != canWin.end())
			return canWin[n];
		else{
			canWin[n] = (!canWinNim(n - 1)) || (!canWinNim(n - 2))
				|| (!canWinNim(n - 3));
			return canWin[n];
		}
	}
};