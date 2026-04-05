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
        // Cần ít nhất 4 phần tử (vd: 1, 5, 2, 6) mới tạo được hình W
        if (n < 4) return 0; 

        // SỬA 1: Dùng -1e18 thay vì LLONG_MIN để cộng trừ an toàn
        const long long INF = -1e18; 
        
        vector<vector<long long>> dp(n, vector<long long>(3, INF));
        dp[0][0] = nums[0];
        long long res = INF;

        for(int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                dp[i][0] = max(dp[i-1][0], (long long)nums[i-1]) + nums[i];
                
                long long pre = INF;
                if(dp[i-1][1] != INF) pre = max(dp[i-1][1], pre);
                if(dp[i-1][2] != INF) pre = max(dp[i-1][2], pre);
                if(pre != INF) dp[i][2] = pre + nums[i];
            } else if (nums[i] < nums[i-1]) {
                long long pre = INF;
                if(dp[i-1][1] != INF) pre = max(dp[i-1][1], pre);
                if (i >= 2 && nums[i-1] > nums[i-2]) {
                    if(dp[i-1][0] != INF) pre = max(dp[i-1][0], pre);
                }
                if(pre != INF) dp[i][1] = pre + nums[i];
                dp[i][0] = nums[i];

            } else {
                dp[i][0] = nums[i];
            }
            if(dp[i][2] != INF) res = max(res, dp[i][2]);
        }
        return (res == INF) ? 0 : res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
