#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty()) return 0;
		int size = citations.size();
		int left = 0;
		int right = size - 1;
		int mid = 0;
		while (left <= right){
			mid = (left + right) / 2;
			if (citations[mid] < size - mid){
				left = mid+1;
			}
			else if (citations[mid]>size - mid){
				right = mid - 1;
			}
			else{
				return size-mid;
			}
		}
		return size-mid;
	}
};