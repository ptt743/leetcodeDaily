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
	vector<bool> online;
	long long k;
	long long right = LLONG_MIN;
	int n = online.size();
	if(edges.size()==0) return -1;

		vector<vector<pair<int,long long>>> adj(n);
	    for(auto & item : edges){
		int u = item[0], v = item[1];
		long long d = item[2];
		right = max(right, d);
		adj[u].push_back({v, d});
	    }
		int left = 0;
	    vector<long long> memo(n, -1);
		while(left<= right){
			long long mid = (left + right)/2;
		fill(memo.begin(), memo.end(), -1);
		const long long INF = 1e18;
		auto dfs = [&](auto& self, int u) -> long long {
			if (u == n - 1) return 0;
			if (memo[u] != -1) return memo[u];
			long long min_cost = INF;
			
			for (int i = 0; i < adj[u].size(); i++) {
			    int v = adj[u][i].first;
			    long long d = adj[u][i].second;
			    if ((v == n - 1 || online[v]) && d >= mid) {
				long long next_cost = self(self, v);
				if (next_cost != INF) {
				    min_cost = min(min_cost, next_cost + d);
				}
			    }
			}
			return memo[u] = min_cost;
		    };
			if(dfs(dfs, 0)<=k) left = mid+1;
			else right = mid-1;
		}
		return (right==INT_MIN)?-1:right;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
