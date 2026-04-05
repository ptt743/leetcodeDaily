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
	vector<vector<int>> times;
	int n;
	int k;
	vector<vector<pair<int,int>>> adj(n+1, vector<pair<int,int>>());
	for(int i =0;i< times.size();i++){
		adj[times[i][0]].push_back({times[i][1], times[i][2]});
	}

	priority_queue<pair<int,int>, vector<pair<int,int>> , decltype([](pair<int,int> a, pair<int,int> b){
		return a.second > b.second;
	})> pq;

	vector<int> dist(n+1, INT_MAX);
	dist[k] = 0;
	pq.push({k,0});
	while(!pq.empty()){
		pair<int,int> top = pq.top();
		pq.pop();
		int u = top.first;
		int v = top.second;
		for(int i = 0;i< adj[u].size();i++){
			int d = adj[u][i].first;
			int c = adj[u][i].second;
			if(dist[u] + c < dist[d]){
				dist[d] = dist[u] + c;
				pq.push({d, dist[d]});
			}
		}
	}
	int res = 0;
	for(int i = 1;i<=n;i++){
		res = max(res, dist[i]);
		if(dist[i]==INT_MAX) return -1;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
