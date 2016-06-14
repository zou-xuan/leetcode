#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		int index1 = m - 1;
		int index2 = n - 1;
		int totalIndex = m + n - 1;
		while (index2 >= 0&&index1>=0){
			if (nums2[index2] > nums1[index1]){
				nums1[totalIndex] = nums2[index2];
				totalIndex--;
				index2--;
			}
			else{
				nums1[totalIndex] = nums1[index1];
				totalIndex--;
				index1--;
			}
			
		}
		if (index1 < 0){
			while (index2 >= 0){
				nums1[totalIndex] = nums2[index2];
				index2--;
				totalIndex--;
			}
		}

	}
};