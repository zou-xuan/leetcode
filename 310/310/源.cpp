#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> result;
		int minHeight = n-1;
		for (int i = 0; i < n; i++){
			vector<int> path(n, INT_MAX);
			path[i] = 0;
			for (int j = 0; j < n; j++){
				for (int k = 0; k < edges.size(); k++){
					pair<int, int> p = edges[k];
					if (path[p.first] != INT_MAX){
						int tmp = path[p.first] + 1;
						if (tmp < path[p.second]) path[p.second] = tmp;
						continue;
					}
					if (path[p.second] != INT_MAX){
						int tmp = path[p.second] + 1;
						if (tmp < path[p.first]) path[p.first] = tmp;
						continue;
					}
				}
			}
			sort(path.begin(), path.end());
			int height = path.back();
			if (height < minHeight){
				result.clear();
				result.push_back(i);
				minHeight = height;
			}
			else if (height == minHeight){
				result.push_back(i);
			}
		}
		return result;
	}
};