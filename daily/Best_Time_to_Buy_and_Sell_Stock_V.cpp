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
	vector<int> prices;
	int h;
	int n = prices.size();

	long long dp[1001][501][3];
	for(int i = 0;i< n;i++){
		for(int j = 0;j<=h;j++){
			for(int k = 0;k< 3;k++)
				dp[i][j][k] = 0;
		}
	}
	for(int j = 0;j<=h;j++){
		dp[0][j][1] = -prices[0];
		dp[0][j][2] = prices[0];
	}

	for(int i =1;i<n;i++){
		for(int k= 1;k<=h;k++){
			dp[i][k][0] = max(dp[i-1][k][0], max(dp[i-1][k][1] + prices[i], dp[i-1][k][2]- prices[i]));
			dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
			dp[i][k][2] = max(dp[i-1][k][2], dp[i-1][k-1][0] + prices[i]);
		}
	}

	return dp[n-1][h][0];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
