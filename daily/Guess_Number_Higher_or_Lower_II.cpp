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
	// 1..10 
	// => 6
	// => 7 ..10
	// =>9
	// 9..10
	// => 9
	// =>10
	// 5 + 8 + 9
	int n;

	vector<vector<int>> dp(n+1, vector<int>(n+1,0));
	for(int len = 1; len<=n;len++){
		for(int i =0;i <=n - len;i++){
			int j = i + len;
			dp[i][j] = INT_MAX;
			for(int k = i;k<=j;k++){
				int left = (k-1>=i)?dp[i][k-1]:0;
				int right = (k+1<=j)?dp[k+1][j]:0;
				int temp = k + max(left, right);
				dp[i][j] = min(dp[i][j], temp);
			}
		}
	}
	return dp[1][n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
