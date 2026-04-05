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
	vector<int> nums={9,4,1,3,7};
	int k=4;
	int n = nums.size();
	deque<int> dqmax, dqmin;
	int mod = 1e9 + 7;
	vector<int> dp(n,0);
	for(int i =0;i< n;i++){
		while(!dqmax.empty() && nums[dqmax.back()]<nums[i]) dqmax.pop_back();
		dqmax.push_back(i);
		while(!dqmin.empty() && nums[dqmin.back()] > nums[i]) dqmin.pop_back();
		dqmin.push_back(i);
		deque<int>tmax = dqmax;
		deque<int> tmin = dqmin;
		for(int j = 0;j<=i;j++){
			if(tmax.front()<j) tmax.pop_front();
			if(tmin.front()<j) tmin.pop_front();
			int u = tmin.front();
			int v = tmax.front();
			if(nums[v] - nums[u]<=k){
				if(j-1>=0)
					dp[i] += dp[j-1];
				else dp[i]=1;
				dp[i]%=mod;
			}
		}
	}
	return dp[n-1];
}

void solve2(){
	vector<int> nums;
	int k;

	int n = nums.size();
	deque<int> tmax, tmin;
	vector<int> dp(n+1,0);
	vector<int> prefix(n+1,0);

	dp[0] = 1;
	prefix[0] = 1;
	for(int i = 0,j=0;i< n;i++){
		while(!tmax.empty() && nums[tmax.back()] < nums[i]) tmax.pop_back();
		tmax.push_back(i);
		while(!tmin.empty() && nums[tmin.back()] > nums[i]) tmin.pop_back();
		tmin.push_back(i);
		while(!tmin.empty() && !tmax.rmpty() && nums[tmax.front()] - nums[tmin.front()] >k){
			if(tmin.front()==j) tmin.pop_front();
			if(tmax.front()==j) tmax.pop_front();
			j++;
		}
		dp[i+1] = (prefix[i] - ((j-1>=0)?prefix[j-1]:0) + mod)%mod;
		predix[i+1] = (prefix[i] + dp[i+1])%mod;
	}
	return dp[n];
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
