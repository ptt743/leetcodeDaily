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
	int l;
	int r;
	int len = r- l+1;
	int arr[n][len][2];
	int mod = 1e9+7;
	vector<vector<int>> prev_dp(len, vector<int>(2, 1));
        vector<vector<int>> curr_dp(len, vector<int>(2, 0));
        for (int i = 1; i < n; i++) {
            
            long long prefix_sum = 0; // Lưu tổng các prev_dp[k][0] với k < j
            for (int j = 0; j < len; j++) {
                curr_dp[j][1] = prefix_sum;
                prefix_sum = (prefix_sum + prev_dp[j][0]) % mod;
            }
            
            long long suffix_sum = 0; // Lưu tổng các prev_dp[k][1] với k > j
            for (int j = len - 1; j >= 0; j--) {
                curr_dp[j][0] = suffix_sum;
                suffix_sum = (suffix_sum + prev_dp[j][1]) % mod;
            }
            
            prev_dp = curr_dp;
        }
        
        long long ans = 0;
        for (int i = 0; i < len; i++) {
            ans = (ans + prev_dp[i][0]) % mod;
            ans = (ans + prev_dp[i][1]) % mod;
        }
        
        return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
