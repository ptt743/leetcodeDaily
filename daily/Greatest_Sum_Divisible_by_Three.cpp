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
	vector<int> nums = {1,2,3,4,4};
	int n = nums.size();
	sort(nums.begin(), nums.end());

	vector<int> dp(3,0);
	int result = 0;
	for(int i =0;i< n;i++){
		int pre0 = dp[0];
		int pre1 = dp[1];
		int pre2 = dp[2];
		if(nums[i]%3==0){
			dp[0]+=nums[i];
			
			if(dp[1]>0)dp[1]+=nums[i];
			if(dp[2]>0)dp[2]+=nums[i];
		}  else if(nums[i]%3==1){
			if((pre0 + nums[i])%3==1)
				dp[1] = max(pre1, pre0 + nums[i]);
			if((pre2+ nums[i])%3==0) 
				dp[0] = max(pre0, pre2 + nums[i]);
			if((pre1 + nums[i])%3==2)
				dp[2] = max(pre2, pre1 + nums[i]);
		} else {
			if((pre1+ nums[i])%3==0) dp[0] = max(pre0, pre1 + nums[i]);
			if((pre0 + nums[i])%3==2)dp[2] = max(pre2, pre0 + nums[i]);
			if((pre2 + nums[i])%3==1)dp[1] = max(pre1, pre2 + nums[i]);
		}
	}
	cout<< dp[0]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
