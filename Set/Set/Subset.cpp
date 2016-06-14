#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Subset{
public:
	vector<vector<int>> subsets(vector<int>& s){
		sort(s.begin(), s.end());
		vector<vector<int>> result;
		vector<int> path;
		subsets(s, path, 0, result);
		return result;
	}

private:
	void subsets(const vector<int>& s, vector<int>& path,
		int step, vector<vector<int>>& result){
		if (step == s.size()){
			result.push_back(path);
			return;
		}
		subsets(s, path, step + 1, result);
		path.push_back(s[step]);
		subsets(s, path, step + 1, result);
		path.pop_back();
	}
};