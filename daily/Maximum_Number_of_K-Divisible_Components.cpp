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
	vector<int> values;
	int k;

	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0;i< edges.size();i++){
		int a = edges[i][0];
		int b = edges[i][1];

		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<bool> visited(n,false);
	int result = 0;
	function<int(int)> dfs=[&](int s){
		visited[s] = true;
		int value = values[s]%k;
		for(int item : adj[s]){
			if(!visited[item]){
				value+=dfs(item);
				value%=k;
			}
		}
		if(value%k==0){
			result++;
			return 0;
		}
		return value;
	};
	dfs(0);
	return result;



}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
