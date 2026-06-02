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
	vector<int>& robot;
	vector<vector<int>>& factory;
	sort(robot.begin(), robot.end());
	sort(factory.begin(), factory.end(),[](vector<int> a, vector<int> b){ return a[0] < b[0];});

	int n = robot.size();
	int m = factory.size();

	long long INF = 1e18;
	vector<vector<long long>> dp(m+1, vector<long long>(n+1, INF));
	for(int i =0;i<=m;i++) dp[i][0] = 0;
	for(int i = 1;i<=m;i++){
		for(int j = 1; j<=n;j++){
			int count = factory[i-1][1];
			long long dist = 0 ;
            dp[i][j] = dp[i-1][j];
			for(int k =1; k <=count;k++){
				if(j - k <0) continue;
				dist += abs( robot[j-k] - factory[i-1][0]);
				dp[i][j] = min(dp[i][j], dp[i-1][j-k] + dist);
			}
		}
	}
	return dp[m][n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
