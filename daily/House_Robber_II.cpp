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
    	if(n==0) return 0;
    	if(n==1) return nums[0];
	function<int(int,int)> calc=[&](int start, int end){
		vector<int> dp(n+1,0);
		for(int i = start; i<end;i++){
            		dp[i] = nums[i];
			if(i-1>=start) dp[i] = max(dp[i-1], dp[i]);
			if(i-2>=start) dp[i] = max(dp[i-2]+ nums[i], dp[i]);
		}
		return dp[end-1];
	};
	return max(calc(0,n-1), calc(1,n));

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
