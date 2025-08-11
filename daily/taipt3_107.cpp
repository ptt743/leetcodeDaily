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
	vector<int> nums={1,3};
	int n = nums.size();
	
	int even = 0;
	int odd = 0;
	vector<int> dp(2,0);
	for(int i =0;i<n;i++) {
		if(nums[i]%2==0){
			even++;
			dp[0] = max(dp[0],dp[1]+1);
		} else {
			odd++;
			dp[1] = max(dp[1], dp[0]+1);
		}
	}
	int result = max(odd, max(even, max(dp[1],dp[0])));
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
