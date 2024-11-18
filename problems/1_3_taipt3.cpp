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
struct point{
	int x;
	int y;
	int value;
};
struct option{
	bool operator()(point &a, point&b){
		return a.value > b.value;
	}
};
void solve(){
	vector<vector<int>> moveTime = {{94,79,62,27,69,84},{6,32,11,82,42,30}};
	int inf = 1e9 + 200;
	int n = moveTime.size();
	int m = moveTime[0].size();
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,1,-1};
	vector<vector<int>> f (n, vector<int>(m, inf));
	function<void(int,int)> djk=[&](int x, int y)->void{
		priority_queue<point, vector<point>, option> pq;
		point start= {x,y,0};
		pq.push(start);
		f[x][y] = 0;
		while(!pq.empty()){
			point top = pq.top();
			pq.pop();
			for(int i =0;i<4;i++){
				int u = top.x + dx[i];
				int v = top.y + dy[i];
				int k = top.value;
				if( u>=0 && u<n && v >=0 && v< m){
					int time = max(k + 1, moveTime[u][v]+1);
					if(time< f[u][v]){
						f[u][v] = time;
						pq.push({u,v,time});
					}
				}
			}
		}
	};
	djk(0,0);
	cout<< f[n-1][m-1]<<endl;

	
} 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
