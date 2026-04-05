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
	vector<vector<int>> costs;
	int n = costs.size();
	vector<vector<int>> dp(n+1,vector<int>(3,INT_MAX));
	dp[0] = {0,0,0};
	for(int i =1;i<=n;i++){
		for(int j = 0;j<3;j++){
			for(int k = 0;k <3;k++){
				if(j!=k){
					dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i-1][j]);
				}
			}
		}
	}
	return min(dp[n][0], min(dp[n][1], dp[n][2]));
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
