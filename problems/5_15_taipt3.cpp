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
	vector<int> prices={26,18,6,12,49,7,45,45};
	int n = prices.size();
	vector<int> dp(n+1,1e9);
	dp[0] = prices[0];
	for(int i =0;i< n;i++){
		int count = i+1;
		for(int j =1;j<=count+1;j++){
			if(i + j < n+1) 
				dp[i+ j] = min(dp[i+j], dp[i] + ((i+j<n)?prices[i+j]:0));
		}
	}
	cout<< min(dp[n-1],dp[n])<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
