#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Permutation{
public :
	vector<vector<int>> permute(vector<int>& num){

	}

private :
	void dfs(const vector<int>& num, vector<int>& path,
		vector<vector<int>>& result){
		if (path.size() == num.size()){
			result.push_back(path);
			return;
		}
		for (auto i : num){
			auto pos = find(path.begin(), path.end(), i);

			if (pos == path.end()){
				path.push_back(i);
				dfs(num, path, result);
				path.pop_back();
			}

		}
	}
};