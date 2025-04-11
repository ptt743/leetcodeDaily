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
	int n = nums.size();
	int sum = 0;
	for(int i =0;i< n;i++) sum += nums[i];
	if(sum%2!=0) return false;
	sum/=2;
	vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    dp[0][0] = true;
	for(int i =1;i<=n;i++){
		for(int j = 0;j<=sum;j++){
			if(j-nums[i-1]>=0) dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
			dp[i][j] = dp[i][j] || dp[i-1][j];
		}
	}
	return dp[n][sum];	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
