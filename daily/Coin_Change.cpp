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
	vector<int> coins;
	int amount;
	int n = coins.size();
	vector<int> dp(amount+1,INT_MAX);
	dp[0] = 0;
	for(int i =1;i<=amount;i++){
		for(int j =0;j< n;j++){
			if(i >= coins[j] && dp[i- coins[j]]!=INT_MAX){
				dp[i] = min(dp[i], dp[i - coins[j]] +1);
			}
		}
	}
	return (dp[amount]==INT_MAX)?-1:dp[amount];
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
