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
	int init = 2;
	int res = 0;
	while(n>1){
		if(n%init==0){
			res+= init;
			n/=init;
		}else {
			init++;
		}
	}
	return res;
}

void solve2(){
	int n;
	vector<int> dp(n+1,INT_MAX);
	dp[1] = 0;
	for(int i = 2;i<=n;i++){
		for(int j = 1;j<i;j++){
			if(i%j==0){
				dp[i] = min(dp[i], dp[j] + i/j);
			}
		} 
	}
	return dp[n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
