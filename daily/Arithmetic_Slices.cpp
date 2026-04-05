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
    	if(n<3) return 0;
	vector<int> dp(n+1,0);
	int maxlen = 0;
    	vector<int> prefix(5001,0);
    	int res =0;
	for(int i =2;i< n;i++){
		if(nums[i]- nums[i-1]== nums[i-1] - nums[i-2]){

			dp[i]=dp[i-1]+1;
		}else {
			dp[i]=0;
		}
        	res+=dp[i];
	}
    	int len = maxlen+2;
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
