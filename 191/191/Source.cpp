#include<iostream>
using namespace std;

int convert(int n){
	int oneCount = 0;
	while (n != 0){
		oneCount += (n & 1);
		n=n >> 1;
	}
	return oneCount;
}

void main(){
	cout << convert(1);
}