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
	vector<int> nums={1,-5,-20,4,-1,3,-6,-3};
	int k =2;
	int n = nums.size();
	deque<int> dq;
	vector<int> dp(n+1,0);
	dp[0] = nums[0];
	dq.push_back(0);
	for(int i =1;i<n;i++){
		while(!dq.empty() && dq.front()< i - k) dq.pop_front();
		dp[i] = (dp[dq.front()]) + nums[i];
		while(!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
		dq.push_back(i);
	}
	cout<< dp[n-1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
