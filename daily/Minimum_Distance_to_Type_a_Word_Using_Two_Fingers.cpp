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
	string word;
	int n = word.size();

	function<int(int,int)> getDis = [&](int p , int q){
		int x1 = p/6, y1 = p%6;
		int x2 = q/6, y2 = q%6;
		return abs( x1-x2) + abs( y1- y2);
	};

	int dp[n][26][26];

	for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                fill(dp[i][j], dp[i][j] + 26, INT_MAX >> 1);
            }
        }
        for (int i = 0; i < 26; ++i) {
            dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        }

	for (int i = 1; i < n; ++i) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = getDis(prev, cur);
            for (int j = 0; j < 26; ++j) {
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
            }
	    for (int j = 0; j < 26; ++j) {
	    	int d1 = getDis(j,cur);
                dp[i][cur][prev] = min(dp[i][cur][prev], dp[i - 1][j][prev] + d1);
                dp[i][prev][cur] = min(dp[i][prev][cur], dp[i - 1][prev][j] + d1);
            } 
        }

	int ans = INT_MAX >> 1;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = min(ans, dp[n - 1][i][j]);
            }
        }
        return ans;
		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
