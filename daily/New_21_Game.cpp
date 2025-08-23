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
	int k;
	int maxPts;
	
	vector<double> dp(n+1,0);
	dp[0] = 1;
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=maxPts;j++){
			if((i-j)>=0 && (i-j)<k){
				dp[i] += dp[i-j]/maxPts;
			}
		}
	}
	 result = 0.0;
	for(int i = k;i<=n;i++) result += dp[i];
	return result;
}

void solve2(){
	int n;
	int k;
	int maxPts;

	vector<double> dp(n+1,0);
	dp[0] = 1;
 	double sum = k>0?1:0;
	for(int i =1 ;i<=n;i++){
		dp[i]+= sum/maxPts;
		if(i>=0 && i<k)
			sum+= dp[i];
		if(i- maxPts>=0 && i - maxPts < k){
			sum -= dp[i - maxPts];
		}
	}

	double res = 0;
	for(int i = k ;i<=n;i++) res += dp[i];
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
