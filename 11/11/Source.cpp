#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int area = 0;
		while (left < right){
			int h = min(height[left], height[right]);
			area = max(area, h*(right - left));
			while (height[left] <= h&&left < right) left++;
			while (height[right] <= h&&left < right) right--;
		}
		return area;
	}
};