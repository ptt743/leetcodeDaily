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
	vector<vector<int>> matrix;
	int n = matrix.size();
	vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
	for(int i =0;i< n;i++) dp[0][i] = matrix[0][i];

	for(int i = 1;i< n;i++){
		for(int j = 0;j< n;j++){
			int left = j-1, middle = j, right = j+1;
			if(left>=0) dp[i][j] = min(dp[i][j], dp[i-1][left] + matrix[i][j]);
			dp[i][j] = min(dp[i][j], dp[i-1][middle] + matrix[i][j]);
			if(right < n) dp[i][j] = min(dp[i][j], dp[i-1][right] + matrix[i][j]);
		}
	}
	int res = INT_MAX;
	for(int i = 0;i< n;i++) res = min(res, dp[n-1][i]);
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
