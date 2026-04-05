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
	vector<int> nums;
	int n = nums.size();

	vector<int> dp(n+1,0);
	dp[1] = nums[0];
	for(int i =2;i<=n;i++){
		dp[i] = max(dp[i], dp[i-1]);
		if(i-2>=0)dp[i] = max(dp[i], dp[i-2] + nums[i-1]);
	}
	return dp[n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
