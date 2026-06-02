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

	vector<vector<int>> adj(n,vector<int>());
	for(int i = 0;i< n;i++){
		for(int j = i+1;j<n;j++){
			if(abs(nums[i] - nums[j])<= target){
				adj[j].push_back(i);
			}
		}
	}
    vector<int> dp(n,-1);
    dp[0] = 0;
    for(int i = 0;i< n;i++){
        for(int item : adj[i]){
            if(dp[item]!=-1)
                dp[i] = max(dp[i], dp[item]+1);
        }
    }
	return dp[n-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
