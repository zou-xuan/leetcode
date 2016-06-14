#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> v;
	vector<vector<int>> parent;
	v.push_back(1);
	parent.push_back(v);
	v.push_back(2);
	cout << "----------";
}