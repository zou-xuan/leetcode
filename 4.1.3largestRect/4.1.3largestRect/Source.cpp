#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int largestRect_sample(vector<int> &height){
	stack<int> s;
	height.push_back(0);
	int result = 0;
	for (int i = 0; i < height.size();){
		if (s.empty() || height[i]>height[s.top()]){
			s.push(i++);
		}
		else{
			int tmp = s.top();
			s.pop();
			result = max(result, height[tmp] * (s.empty() ? i : i - s.top() - 1));
		}
	}
	return result;
}