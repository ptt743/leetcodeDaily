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
void solve(){
	vector<vector<int>> grid={{1,1,1,1}};
	int health = 4;
	int n = grid.size();
	int m = grid[0].size();
	bool visited[101][101][101];
	memset(visited, 0, sizeof(visited));
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,-1,1};
	function<void(int,int,int)> dfs=[&](int x, int y, int d)->void{
		visited[x][y][d] = true;
		for(int i =0;i< 4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if( nx <0 || nx >= n || ny <0 || ny >= m ) continue;
			int nd = d - grid[nx][ny];
			if(nd<=0) continue;
			if(visited[nx][ny][nd]) continue;
			dfs(nx, ny, nd);
		}

	};
	int initHealth = health;
	if(grid[0][0]==1) initHealth--;
	dfs(0,0,initHealth);
	for(int i =1;i<=health;i++){
		if(visited[n-1][m-1][i])
		{
			cout<<"Yes"<<endl;
			return;
		}
	}
	cout<<"No"<<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
