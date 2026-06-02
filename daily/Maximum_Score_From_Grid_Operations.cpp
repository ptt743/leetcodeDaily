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
	vector<vector<int>> grid;
	int n = grid.size();
	    vector<vector<long long>> prefix(n+1, vector<long long> (n+1, 0));

	for(int i = 0;i< n;i++){
		for(int j = 0;j< n;j++){
			prefix[j+1][i] = prefix[j][i] + grid[j][i];
		}
	}

	vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));

	for(int i = 0;i<=n;i++){
		for(int j =0; j<=n;j++){
			if(j>i)dp[i][j] = prefix[j][0] - prefix[i][0];
		}
	}
	for(int c = 1;c<n;c++){
		vector<vector<long long>> next_dp (n+1, vector<long long>(n+1,0));
		for(int i =0;i<=n;i++){
			for(int p = 0;p<=n;p++){
				for(int k = 0;k<=n;k++){
					int limit = max( p,k);
					long long cost = 0;
					if(limit > i){
						cost = prefix[limit][c] - prefix[i][c];
					}
					next_dp[i][p] = max( next_dp[i][p], dp[k][i] + cost);
				}
			}
		}
		dp = next_dp;
	}
	long long res = 0;
	for(int i = 0;i<=n;i++){
		res = max( res, dp[i][0]);
	}
	return res;	
}
void solve2(){
	vector<vector<int>> grid;
	int n = grid.size();
        
        vector<vector<long long>> pre(n + 1, vector<long long>(n, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                pre[i + 1][j] = pre[i][j] + grid[i][j];
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

        for (int p = 0; p <= n; ++p) {
            for (int i = 0; i <= n; ++i) {
                if (i > p) dp[p][i] = pre[i][0] - pre[p][0];
                else dp[p][i] = 0;
            }
        }

        for (int c = 1; c < n; ++c) {
            vector<vector<long long>> next_dp(n + 1, vector<long long>(n + 1, 0));
            
            for (int i = 0; i <= n; ++i) { // i là H[c] (độ cao cột hiện tại)
                vector<long long> pref_max(n + 1, 0);
                vector<long long> suff_max(n + 1, 0);

                pref_max[0] = dp[0][i];
                for (int p = 1; p <= n; ++p) {
                    pref_max[p] = max(pref_max[p - 1], dp[p][i]);
                }

                suff_max[n] = dp[n][i] + (n > i ? pre[n][c] - pre[i][c] : 0);
                for (int p = n - 1; p >= 0; --p) {
                    long long val = dp[p][i] + (p > i ? pre[p][c] - pre[i][c] : 0);
                    suff_max[p] = max(suff_max[p + 1], val);
                }

                for (int k = 0; k <= n; ++k) {
                    long long term1 = pref_max[k] + (k > i ? pre[k][c] - pre[i][c] : 0);
                    long long term2 = (k + 1 <= n) ? suff_max[k + 1] : 0;
                    
                    next_dp[i][k] = max(term1, term2);
                }
            }
            dp = next_dp; // Chuyển trạng thái
        }

        long long ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans = max(ans, dp[i][0]);
        }
        
        return ans;	
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
