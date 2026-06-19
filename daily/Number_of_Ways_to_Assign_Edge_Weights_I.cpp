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
	vector<vector<int>> edges;
	int n = edges.size()+1;
	vector<bool> visited(n+1, false);
	vector<vector<int>> adj(n+1, vector<int>());
	for(vector<int> item: edges){
		int a = item[0];
		int b = item[1];
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> dist(n+1,0);
	function<void(int)> dfs=[&](int s){
		visited[s] = true;
		for(int item : adj[s]){
			if(!visited[item]){
				dist[item] = dist[s]+1;
				dfs(item);
			}
		}
	};
	dfs(1);
	long long MOD = 1e9 + 7;
	function<long long(long long, long long)> modPow=[&](long long base, long long exp) {
		long long res = 1;
		base = base % MOD;
		while (exp > 0) {
		    if (exp % 2 == 1) res = (res * base) % MOD;
		    base = (base * base) % MOD;
		    exp /= 2;
		}
		return res;
	};
	int maxVal = 0;
	for(int i = 1;i<=n;i++) {
		maxVal = max(maxVal, dist[i]);
	}
	if (maxVal == 0){
		return 0;
	}
	return modPow(2ll, maxVal - 1);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
