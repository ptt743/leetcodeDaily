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
    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k * k <= i; ++k) {
            if (!dp[i - k * k]) {
                dp[i] = true; // Thì người chơi hiện tại chắc chắn nắm thế thắng
                break;        // Đã tìm được 1 đường thắng thì không cần thử tiếp nữa
            }
        }
    }
    return dp[n];		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
