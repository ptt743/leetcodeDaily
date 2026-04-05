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
	vector<vector<int>> pairs;
	int n = pairs.size();

	sort(pairs.begin(), pairs.end(), [&](vector<int>&a, vector<int>&b){return a[1] < b[1];});

	vector<int> dp(n,1);
	for(int i = 0;i< n;i++){
		for(int j = i -1;j>=0;j--){
			if(pairs[j][1] <pairs[i][0]) dp[i] = max(dp[i], dp[j]+1);		
		}
	}
	int ans = 0;
	for(int i = 0;i< n;i++) ans = max(ans, dp[i]);
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
