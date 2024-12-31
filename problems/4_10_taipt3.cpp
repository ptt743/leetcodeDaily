#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
struct node{
	int x;
	int y;
	long long dist;
	int mode;
};

struct compare{
	bool operator() (node& a, node& b){
		return a.dist > b.dist;		
	}
};

void solve(){
	vector<vector<long long>> moveTime={{0,1},{1,2}};
	int n = moveTime.size();
	int m = moveTime[0].size();
	vector<vector<long long>> dist(n, vector<long long>(m,1e16));
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,-1,1};
	function<void()> dijkstra=[&]()-> void{
		priority_queue<node, vector<node>, compare> pq;
		dist[0][0] = 0;
		pq.push({0,0,0,0});
		while(!pq.empty()){
			node top = pq.top();
			pq.pop();
			int x = top.x;
			int y = top.y;
			int mode = top.mode;
			long long dis = top.dist;
			for(int i =0;i< 4;i++){
				int nx = top.x + dx[i];
				int ny = top.y + dy[i];
				if(nx<0 || nx >=n || ny <0 || ny >=m) continue;
				int moveCost = (mode==0)?1:2;
				long long d = max(moveTime[nx][ny], dis) + moveCost;
				if(dist[nx][ny] > d){
					dist[nx][ny] = d;
					pq.push({nx,ny, dist[nx][ny], 1 - mode});
				}
			}
		}
	};
	dijkstra();
	cout<< dist[n-1][m-1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
