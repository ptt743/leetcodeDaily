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
	vector<vector<int>>& grid;
	int k;

	int n = grid.size();
	int m = grid[0].size();

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1,-1)));
	
	int val  = grid[0][0];
	if(val!=0) dp[0][0][1] = (val==1)?1:2;
	else dp[0][0][0] = 0;

	for(int i =0;i<n; i++){
		for(int j =0;j<m;j++){
			val = grid[i][j];
			for(int h = 0;h<=k;h++){
				if(val==0){
					if(i-1>=0 && dp[i-1][j][h]!=-1)dp[i][j][h] = max(dp[i][j][h],dp[i-1][j][h]);
					if(j-1>=0 && dp[i][j-1][h]!=-1)dp[i][j][h] = max(dp[i][j][h],dp[i][j-1][h]);
				}
				if(val==1 && h>=1){
					if(i-1>=0 && dp[i-1][j][h-1]!=-1)dp[i][j][h] = max(dp[i][j][h],dp[i-1][j][h-1]+1);
					if(j-1>=0 && dp[i][j-1][h-1]!=-1)dp[i][j][h] = max(dp[i][j][h],dp[i][j-1][h-1]+1);
				}
				if(val==2 && h>=1) {
					if(i-1>=0 && dp[i-1][j][h-1]!=-1)dp[i][j][h] = max(dp[i][j][h],dp[i-1][j][h-1]+2);
					if(j-1>=0 && dp[i][j-1][h-1]!=-1)dp[i][j][h] = max(dp[i][j][h],dp[i][j-1][h-1]+2);
				}
			}
		}
	}
	int res =-1;
	for(int i =0;i<=k;i++) res = max(res, dp[n-1][m-1][i]);
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
