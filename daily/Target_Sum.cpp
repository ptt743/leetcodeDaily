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
	int target;

	int n = nums.size();

	vector<unordered_map<int,int>> dp(n);
	dp[0][-nums[0]]+=1;
	dp[0][nums[0]]+=1;
	for(int i= 1;i< n;i++){
		for(auto& item : dp[i-1]){
			dp[i][item.first+nums[i]]+= item.second;
			dp[i][item.first-nums[i]]+=item.second;
		}
	}
	return dp[n-1][target];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
