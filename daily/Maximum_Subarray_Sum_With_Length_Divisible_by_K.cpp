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
	int k;
	int n = nums.size();

	vector<long long> prefix(n+1,0);
	for(int i = 1;i<=n;i++){
		prefix[i] = prefix[i+1] + nums[i-1];
	}

	vector<long long> dp(n+1,0);
	long long maxVal = -1e9*n;
	for(int i =k;i<=n;i++){
		dp[i] = max(dp[i-k]+ prefix[i] - prefix[i-k], prefix[i]- prefix[i-k]);
		maxVal = max(maxVal, dp[i]);
	}
	return maxVal;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
