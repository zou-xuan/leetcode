#include<iostream>
#include<map>
using namespace std;

class Solution{
public :
	int BSTNum(int n){
		map<int, int> typemap;
		return getNum(n, typemap);
	}

	int getNum(int n, map<int, int> &typeMap){
		if (typeMap.find(n) != typeMap.end()){
			return typeMap.find(n)->second;
		}
		else if(n==0||n==1){
			return 1;
		}
		
		else{
			int result = 0;
			for (int i = 0; i <n; i++){
				result = result + getNum(i,typeMap) * getNum(n - 1 - i,typeMap);
			}
			return result;
		}
	}
};

void main(){
	Solution s;
	cout<<s.BSTNum(3);
}