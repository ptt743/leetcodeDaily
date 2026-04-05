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
	vector<vector<int>> edges;

	vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
	for(int i = 0;i< edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];

		adj[u].push_back({v,w});
		adj[v].push_back({u,2*w});
	}
	struct option{
		bool operator()(pair<int,int>&a, pair<int,int>&b){
			return a.first > b.first;
		}
	};
	priority_queue<pair<int,int>, vector<pair<int,int>>, option> pq;

	pq.push({0,0});
	vector<int> dist(n,INT_MAX);
	while(!pq.empty()){
		pair<int,int> top = pq.top();
		pq.pop();
		int u = top.second;
		int cost = top.first;

		for(int i = 0;i< adj[u].size();i++){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if(dist[v] > cost + w){
				dist[v] = cost + w;
				pq.push({dist[v],v});
			}
		}
	}
	return dist[n-1]==INT_MAX?-1:dist[n-1];

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
