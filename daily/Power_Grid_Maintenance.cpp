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
	int c = 5;
	vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
	vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};

	int m = queries.size();
	map<int,set<int>>mp;
	vector<vector<int>> graph(c+1,vector<int>());

	for(int i =0;i< connections.size();i++){
		int u = connections[i][0];
		int v = connections[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	map<int,int> gall;
	map<int,bool> off;
	int index = 1;
	vector<int> visited(c+1, false);
	function<void(int)> bfs=[&](int s){
		queue<int> qq;
		qq.push(s);
		visited[s] = true;
		gall[s] = index;
		while(!qq.empty()){
			int front = qq.front();
			qq.pop();
			for(int i = 0;i< graph[front].size();i++){
				int v = graph[front][i];
				if(!visited[v]){
					visited[v] = true;
					qq.push(v);
					gall[v] = index;
				}
			}
		}
	};
	for(int i = 1;i<=c;i++){
		if(!visited[i]){
			index++;
			bfs(i);
		}
	}

	for(int i = 1;i<=c;i++){
		mp[gall[i]].insert(i);
	}
	vector<int> res;
	for(int i = 0;i< queries.size();i++){
		int type = queries[i][0];
		int sta = queries[i][1];
		int ind = gall[sta];
		if(type ==1){
			if(!off[sta]){
				res.push_back(sta);
				continue;
			}
			res.push_back((mp[ind].empty()?-1:(*mp[ind].begin())));

		} else {
			off[sta] = true;
			mp[ind].erase(sta);
		}
	}


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
