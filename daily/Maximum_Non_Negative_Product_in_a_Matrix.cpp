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
	int n = grid.size();
	int m = grid[0].size();
    int mod = 1e9 +7;
	vector<vector<pair<long long,long long>>> dp(n, vector<pair<long long, long long>>(m, {LLONG_MAX, LLONG_MIN}));
	dp[0][0] = {grid[0][0], grid[0][0]};
	for(int i = 0;i<n;i++){
		for(int j = 0; j< m;j++){
			long long currVal = grid[i][j];
			if(i-1>=0){
				long long tempMax = max( currVal * dp[i-1][j].first, currVal*dp[i-1][j].second);
				long long tempMin = min( currVal * dp[i-1][j].first, currVal*dp[i-1][j].second);
				dp[i][j].first = min(dp[i][j].first, tempMin);
				dp[i][j].second = max(dp[i][j].second, tempMax);
			}
			if(j-1>=0){
				long long tempMax = max( currVal * dp[i][j-1].first, currVal*dp[i][j-1].second);
				long long tempMin = min( currVal * dp[i][j-1].first, currVal*dp[i][j-1].second);
				dp[i][j].first = min(dp[i][j].first, tempMin);
				dp[i][j].second = max(dp[i][j].second, tempMax);
			}
			
		}
	}
	return (dp[n-1][m-1].second>=0)?(dp[n-1][m-1].second%mod):-1;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
