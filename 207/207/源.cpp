#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 0 || prerequisites.empty()) return true;
		vector<int> v;
		vector<vector<int>> course(numCourses,v);
		for (pair<int, int> p : prerequisites){
			course[p.second].push_back(p.first);
		}
		vector<int> visited(numCourses);
		for (int i = 0; i < numCourses; i++){
			if (!dfs(i, course, visited)){
				return false;
			}
		}
		return true;


	}

	bool dfs(int index, vector<vector<int>>& course, vector<int>& visited){
		visited[index] = 1;
		vector<int> next = course[index];
		for (int val : next){
			if (visited[val] == 1) return false;
			if (visited[val] == 0){
				if (!dfs(val, course, visited))
					return false;
			}
		}
		visited[index] = 2;
		return true;
	}
};
