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

	map<int,int> mp;
	for(int i = 0;i< n;i++) mp[nums[i]]++;
	vector<pair<int,int>> arr;
	for(auto &it : mp){
		arr.push_back({it.first, it.second});
	}
	int m = arr.size();
	vector<int> dp(m,0);
	for(int i =0;i< m;i++){
		dp[i] = arr[i].first* arr[i].second;
		for(int j = 0;j< i;j++){
			if(arr[j].first != arr[i].first-1)
				dp[i] = max(dp[i], arr[i].first * arr[i].second + dp[j]);
		}
	}
	int maxVal= 0;
	for(int i =0;i< n;i++) maxVal = max(maxVal, dp[i]);
	return maxVal;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
