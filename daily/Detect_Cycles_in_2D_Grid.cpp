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
	vector<vector<char>> grid;
	int n = grid.size();
	int m = grid[0].size();
	vector<vector<bool>> visited ( n, vector<bool>(m,false));
	vector<int> dx ={1,-1,0,0};
	vector<int> dy ={0,0,1,-1};
	function<bool(pair<int,int>,pair<int,int>)> dfs=[&](pair<int,int> s,  pair<int,int>pre){
		visited[s.first][s.second]=true;
		bool check = false;
		for(int i=0;i<4;i++){
			int nx = s.first + dx[i];
			int ny = s.second + dy[i];
			if(nx>=0 && nx <n && ny >=0 && ny<m && grid[nx][ny]== grid[s.first][s.second]){
				pair<int,int> nxt ={nx, ny};
				if(nxt != pre){
					if(visited[nx][ny]) return true;
					else {
						check |=dfs(nxt, s);
					}
					if(check) return true;
				}
			}
		}
		return false;
	};
	for(int i =0;i< n;i++){
		for(int j =0;j< m;j++){
			if(visited[i][j]!=true){
				if(dfs({i,j},{i,j})) return true;
			}
		}
	}
	return false;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
