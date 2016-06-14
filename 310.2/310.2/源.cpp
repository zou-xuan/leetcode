#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> v;
		if (n == 1){
			v.push_back(0);
			return v;
		}
		vector<vector<int>> adj(n,v);
		for (int i = 0; i < edges.size(); i++){
			pair<int, int> p = edges[i];
			adj[p.first].push_back(p.second);
			adj[p.second].push_back(p.first);
		}
		vector<int> leaf;
		for (int i = 0; i < adj.size(); i++){
			if (adj[i].size() == 1){
				leaf.push_back(i);
			}
		}
		while (n>2){
			n -= leaf.size();
			vector<int> newLeaf;
			for (int i : leaf){
				int tmp = adj[i][0];
				adj[tmp].erase(remove(adj[tmp].begin(), adj[tmp].end(), i), adj[tmp].end());
				if (adj[tmp].size() == 1) newLeaf.push_back(tmp);
			}
			leaf = newLeaf;
		}
		return leaf;
	}
};