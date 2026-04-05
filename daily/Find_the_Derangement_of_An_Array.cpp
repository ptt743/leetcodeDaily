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
	int n;
	if (n == 0)
            return 1;
        if (n == 1)
            return 0;
	vector<long long> dp(n+1,0);
	dp[1] = 0;
	dp[2] =1;
	int mod = 1e9 + 7;
	for(int i = 3;i<=n;i++){
		dp[i] = (i-1) * (dp[i-1] + dp[i-2]);
		dp[i]%=mod;
	}
	return dp[n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
