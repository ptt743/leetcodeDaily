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
	int n;
	vector<int> dp(n,0);
	dp[0] = 1;
	for(int i =1;i<n;i++){
		dp[i] = dp[i-1] +1;
		for(int j = 0;j< i;j++){
			if(i-j-2>0){
				dp[i] = max(dp[i], dp[j]*(i-j-1));
			}
		}
	}
	return dp[n-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
