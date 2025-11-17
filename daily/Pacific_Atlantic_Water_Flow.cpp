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
	vector<vector<int>> heights={{1}};

	int n = heights.size();
	int m = heights[0].size();
	
	queue<pair<int,int>> qq1;
	vector<vector<bool>> visited1 = vector<vector<bool>> (n, vector<bool>(m,false));
	for(int i =0;i< n;i++) qq1.push(make_pair(i,0)), visited1[i][0] = true;
	for(int i = 1;i<m;i++) qq1.push(make_pair(0,i)), visited1[0][i] = true;
	
	vector<int> dx = {-1,1,0,0};
	vector<int> dy = {0,0,1,-1};
	while(!qq1.empty()){
		pair<int,int> top = qq1.front();
		qq1.pop();
		for(int i =0;i< 4;i++){
			int nx = top.first + dx[i];
			int ny = top.second + dy[i];
			if(nx < 0 || nx>=n || ny<0 || ny>=m || visited1[nx][ny]) continue;
			if(heights[nx][ny] <  heights[top.first][top.second]) continue;
			visited1[nx][ny] = true;
			qq1.push(make_pair(nx,ny));
		}
	}

	queue<pair<int,int>> qq2;
	vector<vector<bool>> visited2 = vector<vector<bool>> (n, vector<bool>(m,false));

	for(int i = 0;i<n;i++) qq2.push(make_pair(i,m-1)), visited2[i][m-1] = true;
	for(int i = 0;i<m-1;i++) qq2.push(make_pair(n-1,i)), visited2[n-1][i] = true;

	while(!qq2.empty()){
		pair<int,int> top = qq2.front();
		qq2.pop();
		for(int i =0;i<4;i++){
			int nx = top.first + dx[i];
			int ny = top.second + dy[i];

			if(nx<0 || nx >= n || ny<0 || ny>=m || visited2[nx][ny]) continue;
			if(heights[nx][ny] <  heights[top.first][top.second]) continue;
			visited2[nx][ny] = true;
			qq2.push(make_pair(nx,ny));
		}
	}
	vector<pair<int,int>> res;
	for(int i =0;i<n;i++)
		for(int j = 0;j<m;j++)
			if(visited1[i][j] && visited2[i][j]){
				res.push_back(make_pair(i,j));
			}
	return res.size();


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
