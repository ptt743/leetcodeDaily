#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n;
	vector<vector<int>> roads;

	vector<vector<pair<int,int>>> adj(n+1);
	for(auto & item : roads){
		int u = item[0];
		int v = item[1];
		int val = item[2];

		adj[u].push_back({v,val});
		adj[v].push_back({u, val});
	}
	vector<bool> visited(n+1,false);
	queue<int> qq;
	qq.push(1);
	visited[1] = true;

	int min_score = 1e9;
	while(!qq.empty()){
		int front = qq.front();
		qq.pop();
		for(auto& item: adj[front]){
			int next = item.first;
			int val = item.second;

			min_score = min(min_score, val);
			if(!visited[next]){
				visited[next] = true;
				qq.push(next);
			}
		}
	}
	return min_score;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
