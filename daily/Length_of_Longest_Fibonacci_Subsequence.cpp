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
	vector<int> arr;
	int n = arr.size();
	unordered_map<int,int> mp;
	for(int i =0;i< n;i++) mp[arr[i]] = i;
	vector<vector<int>> dp(n,vector<int>(n,2));
	int ans = 0;
	for(int i = 0;i< n;i++){
		for(int j = 0;j < i;j++){
			int temp = arr[i] - arr[j];
			if(mp.find(temp)!=mp.end() && temp < arr[j]){
				int index = mp[temp];
				dp[i][j] = max(dp[i][j], dp[j][index]+1);
			}
			ans = max(ans, dp[i][j]);
		}
	}
	return (ans==2)?0:ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
