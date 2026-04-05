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
	vector<vector<int>>& flights;
	int src;
	int dst;
	int k;
	int m= flights.size();
	vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
	for(int i = 0;i<m;i++){
		adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
	}
	struct node {
		int id;
		int cost;
		int count;
	};
	vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
	for(int i = 0;i<=k+1;i++) dist[src][i] = 0;

	priority_queue<node, vector<node>, decltype([](node a, node b){ return a.cost > b.cost; })> pq;
	pq.push({src,0,0});
	while(!pq.empty()){
		node top = pq.top();
		pq.pop();
		int id = top.id;
		int count =  top.count;
		int cost = top.cost;
		for(int i =0;i< adj[id].size();i++){
			int nxt = adj[id][i].first;
			int c = adj[id][i].second;
			if( count<=k && dist[nxt][count+1] > cost + c ){
				dist[nxt][count+1] = cost + c;
				pq.push({nxt, cost + c, count+1});
			}
		}
	}
	int minVal = INT_MAX;
	for(int i = 0;i<=k+1;i++) minVal = min(dist[dst][i], minVal);
	return (minVal==INT_MAX)?-1:minVal;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
