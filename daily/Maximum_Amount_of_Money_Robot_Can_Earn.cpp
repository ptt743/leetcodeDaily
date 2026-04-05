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
	vector<vector<int>> coins;
	int n = coins.size();
	int m = coins[0].size();
	vector memo(m, vector(n, array<int, 3>{INT_MIN, INT_MIN, INT_MIN}));
	function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (i >= m || j >= n) {
                return INT_MIN;
            }

            int x = coins[i][j];
            // arrive at the destination
            if (i == m - 1 && j == n - 1) {
                return k > 0 ? max(0, x) : x;
            }

            int res = memo[i][j][k];
            if (res != INT_MIN) {
                return res;
            }
            // not neutralize
            res = max(dfs(i + 1, j, k), dfs(i, j + 1, k)) + x;
            if (k > 0 && x < 0) {
                // neutralize
                res = max({res, dfs(i + 1, j, k - 1), dfs(i, j + 1, k - 1)});
            }
            return memo[i][j][k] = res;
        };

	return dfs(0, 0, 2);

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
