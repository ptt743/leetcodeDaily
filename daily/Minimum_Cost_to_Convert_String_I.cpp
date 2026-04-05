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
	string source;
	string target;

	vector<char> original;
	vector<char> changed;
	vector<int> cost;

	int n = source.size();

	int len = original.size();
	vector<vector<int>> dist(26,vector<int>(26,INT_MAX));
	vector<vector<pair<int,long long>>> adj(26, vector<pair<int,long long>>());
	for(int i =0;i< len;i++){
		adj[original[i]-'a'].push_back({changed[i]-'a', cost[i]});
	}

	struct option{
		bool operator()(pair<int,long long>a, pair<int,long long> b){
			return a.second > b.second;
        }
	};

	for(int i=0;i< 26;i++){
		priority_queue<pair<int,long long>, vector<pair<int,long long>>, option> pq;
		dist[i][i] = 0;
		pq.push({i, 0});
		while(!pq.empty()){
			pair<int,long long> top = pq.top();
			pq.pop();
			int u = top.first;
			long long cos = top.second;
			for(pair<int,long long> item: adj[u]){
				if(cos + item.second < dist[i][item.first]){
					dist[i][item.first] = cos + item.second;
					pq.push({item.first, dist[i][item.first]});
				}
			}
		}
        
	}
    	long long costs = 0;
    	for(int i = 0;i< n;i++){
		if(dist[source[i]-'a'][target[i]-'a']==INT_MAX){
			return -1;
		}
		costs +=dist[source[i]-'a'][target[i]-'a'];
	}
	return costs;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
