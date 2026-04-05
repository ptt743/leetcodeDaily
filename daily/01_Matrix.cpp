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
	vector<vector<int>> mat;
	int n = mat.size();
	int m = mat[0].size();

	queue<pair<int,int>> qq;
	vector<vector<int>> dp(n, vector<int>(m,0));
	for(int i = 0;i< n;i++){
		for(int j = 0;j< m;j++){
			if(mat[i][j]==1) dp[i][j] = -1;
			else {
				qq.push({i,j});
			}
		}
	}
	vector<int> dx ={1,-1,0,0};
	vector<int> dy ={0,0,1,-1};
	while(!qq.empty()){
		pair<int,int> front = qq.front();
		qq.pop();
		for(int i =0;i< 4;i++){
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if(nx>=0 && nx < n && ny >=0 && ny <m && dp[nx][ny]==-1){
				dp[nx][ny] = dp[front.first][front.second] + 1;
				qq.push({nx,ny});
			}
		}
		
	}
	return dp;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
