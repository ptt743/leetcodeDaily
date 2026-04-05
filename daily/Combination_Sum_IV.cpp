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
	vector<unsigned int>nums;
	int target;

	int n = nums.size();
	vector<int> dp(target+1, 0);

	for(int j = 0; j <= target;j++){
		for(int i=0;i< n;i++){
			if(j - nums[i]>=0) dp[j] += dp[j - nums[i]];
		}
	}
	return dp[target];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
