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
	vector<int> a;
	int n = a.size();

	vector<pair<int,int>> dp(n,{1,1});
	int ans = 1;
	for(int i =1 ;i< n;i++){
		if(i%2!=0){
			if(a[i]> a[i-1]) dp[i].second = max(dp[i].second, dp[i-1].first +1);
			if(a[i]<a[i-1]) dp[i].first = max(dp[i].first, dp[i-1].second+1); 
		} else{
			if(a[i]< a[i-1]) dp[i].first = max( dp[i].first, dp[i-1].second+1);
			if(a[i]> a[i-1]) dp[i].second = max( dp[i].second, dp[i-1].first+1);
		}
		ans = max(ans, max(dp[i].first , dp[i].second));
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
