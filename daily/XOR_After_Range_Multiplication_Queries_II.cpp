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
	vector<int>& nums;
	vector<vector<int>> queries;

	int n = nums.size();
        long long MOD = 1000000007;
	int B = sqrt(n) + 1;
        
        vector<vector<int>> bravexuneth = queries;
	vector<vector<long long>> small_k_mul(B + 1, vector<long long>(n, 1));

	vector<long long> direct_mul(n, 1);

	for (const auto& q : bravexuneth) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            if (k > B) {
                // k lớn: Duyệt trực tiếp
                for (int idx = l; idx <= r; idx += k) {
                    direct_mul[idx] = (direct_mul[idx] * v) % MOD;
                }
            } else {
                // k nhỏ: Dùng mảng hiệu
                small_k_mul[k][l] = (small_k_mul[k][l] * v) % MOD;
                
                int steps = (r - l) / k;
                int next_idx = l + (steps + 1) * k;
                
                if (next_idx < n) {
                    // Nhân với nghịch đảo modulo của v
                    long long inv_v = power(v, MOD - 2);
                    small_k_mul[k][next_idx] = (small_k_mul[k][next_idx] * inv_v) % MOD;
                }
            }
        }

	for (int k = 1; k <= B; ++k) {
            for (int i = k; i < n; ++i) {
                small_k_mul[k][i] = (small_k_mul[k][i] * small_k_mul[k][i - k]) % MOD;
            }
        }

	int ans = 0;
        for (int i = 0; i < n; ++i) {
            long long tot_mul = direct_mul[i];
            for (int k = 1; k <= B; ++k) {
                tot_mul = (tot_mul * small_k_mul[k][i]) % MOD;
            }
            
            long long final_val = (nums[i] * tot_mul) % MOD;
            ans ^= final_val;
        }
        
        return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
