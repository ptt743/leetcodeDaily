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
	int n = s.size();

	vector<vector<int>> dp(n+1, vector<int>(2,0));

	for(int i = n-1;i>=0;i--){
		if(s[i]=='0'){
			dp[i][0] = min(dp[i+1][0], dp[i+1][1]);
			dp[i][1] = dp[i+1][1]+1;
		}else {
			dp[i][0] = min(dp[i+1][1], dp[i+1][0]) +1;
			dp[i][1] = dp[i+1][1];
		}
	}
	return min(dp[0][1], dp[0][0]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
