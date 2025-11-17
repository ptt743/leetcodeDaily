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
	vector<string> strs;

	int m;
	int n;
	int len = strs.size();

	vector<vector<int>> dp(m+1, vector<int>(n+1,0));
	for(string s: strs){
		int zero = 0, one = 0;
		for(char c: s){
			if(c=='0') zero++;
			else one++;
		}

		for(int i = m ;i>=zero; i--){
			for(int j = n;j>=one;j--){
				dp[i][j] = max(dp[i][j], dp[i- zero][j-one]+1);
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
