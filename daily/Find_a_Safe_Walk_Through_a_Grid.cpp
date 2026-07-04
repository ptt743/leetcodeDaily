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
	vector<vector<int>> grid;
	int health;
	int n = grid.size();
	int m = grid[0].size();
	vector<int> dx = {-1,1,0,0};
	vector<int> dy = {0,0,-1,1};
	vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
	dist[0][0] = grid[0][0];
	priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, decltype([](pair<int,pair<int,int>> a, pair<int, pair<int,int>> b){ return a.first > b.first;})> pq;
	
	pq.push({dist[0][0],{0,0}});
	while(!pq.empty()){
		pair<int,pair<int,int>> top = pq.top();
		int d = top.first;
		int x = top.second.first;
		int y = top.second.second;
		pq.pop();
		for(int i = 0;i< 4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if( nx>=0 && nx < n && ny>=0 && ny <m){
				if(d + grid[nx][ny]< dist[nx][ny]){
					dist[nx][ny] = d + grid[nx][ny];
					pq.push({dist[nx][ny],{nx,ny}});
				}
			}
		}
	}
	return (dist[n-1][m-1] <health);

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
