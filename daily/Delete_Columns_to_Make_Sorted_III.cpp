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
	int n = strs.size();
	int len = strs[0].size();

	vector<int> dp(len,1);
	int maxValue = 1;

	for(int i = 1;i< len;i++){
		for(int j = 0;j< i;j++){
			bool check = true;
			for(int k = 0;k<n;k++){
				if(strs[k][i] < strs[k][j]){
					check = false;
					break;
				}
			}
			if(check) dp[i] = max(dp[i], dp[j] +1);
		}
		maxValue = max(maxValue, dp[i]);
	}
	return len - maxValue;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
