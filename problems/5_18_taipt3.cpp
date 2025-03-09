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
	int n=4;
	int delay=1;
	int forget=3;
	long long mod = 1e9+7;
	long long res = 1;
	vector<long long> dp(n,0);
	dp[0] =1;
	int teller = 0;
	for(int i =1;i< n;i++){
		if(i - delay>=0){
			teller= (teller%mod + dp[i-delay]%mod)%mod;
		}
		if(i - forget>=0){
			teller= (teller%mod -  dp[i-forget]%mod + mod)%mod;
		}
		dp[i] = teller;
		res = (res%mod + dp[i]%mod)%mod;
		if(i - forget >=0){
			res = (res%mod - dp[i-forget]%mod + mod)%mod;
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
