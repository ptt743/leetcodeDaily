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
	vector<int> nums1;
	vector<int> nums2;
	int n = nums1.size();
	int m = nums2.size();

	vector<vector<long long>> dp(n+1, vector<long long>(m+1,-1e18));
	// index i , len j;
	dp[0][0] = 0;
    	long long maxVal = LLONG_MIN;
	for(int i=1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			dp[i][j] = max(dp[i][j], max((long long)nums1[i-1] * nums2[j-1], max((long long)nums1[i-1]* nums2[j-1]+ dp[i-1][j-1],max(dp[i][j-1], dp[i-1][j]))));		
			maxVal = max(maxVal, dp[i][j]);
		}

	}
	return maxVal;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
