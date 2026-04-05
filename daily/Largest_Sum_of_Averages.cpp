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
	int K;

	int n = nums.size();

	vector<vector<double>> dp ( n+1, vector<double>(K+1,0));

	vector<double> P (n+1, 0);
	for(int i =1;i<=n;i++){
		P[i] = P[i-1] + nums[i-1];
	}

	for(int i =0;i<=n;i++){
		dp[i][0] = (P[n] - P[i])/(n-i);
	}
	for(int k = 1;k<K;k++){
		for(int i =0;i<n;i++){
			for(int j = i+1;j<n;j++){
				dp[i][k] = max(dp[i][k], (P[j] - P[i])/(j-i) + dp[j][k-1]);
			}
		}
	}
	double ans = 0;
	for(int i = 0;i<k;i++) ans = max(ans, dp[0][i]);
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
