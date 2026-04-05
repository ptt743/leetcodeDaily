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
	string s;

	string s2 = s;
	reverse(s2.begin(), s2.end());
	int n = s.size();
	vector<vector<int>> dp(n+1, vector<int>(n+1,0));

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n,j++){
			if(s[i-1]==s2[j-1]){
				dp[i][j] = max(dp[i][j], dp[i-1]+ 1);
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
