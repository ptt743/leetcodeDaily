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
	vector<int>nums;
	int k;
	int n = nums.size();
	int sum = 0;
	for(int item : nums){
		sum+=item;
	}
	if(sum%k!=0) return false;
	int target = sum/k;
	sort(nums.begin(), nums.end(), [](int a, int b){ return a> b;});

	vector<int> dp(1 << n, -1);
        dp[0] = 0;
	for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    int next_mask = mask | (1 << i);
                    if (dp[mask] + nums[i] <= target) {
                        dp[next_mask] = (dp[mask] + nums[i]) % target;
                    }
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
