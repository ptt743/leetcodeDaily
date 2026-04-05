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
	vector<int> nums;
	int n = nums.size();
	vector<pair<int,int>> dp(n,{1,1});
	int maxLen = 1;
	for(int i = 0;i< n;i++){
		for(int j = 0; j< i;j++){
			if(nums[j]<nums[i]){
				int len  = dp[j].first+1;
				if(len> dp[i].first) dp[i] = {len,dp[j].second};
				else if(len == dp[i].first) dp[i].second+= dp[j].second;
				maxLen = max(maxLen, len);
			}
		}
	}
	int res = 0;
	for(int i = 0;i< n;i++)
		if(dp[i].first == maxLen) res+= dp[i].second;
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
