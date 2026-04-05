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
	vector<int> days;
	vector<int> costs;
	int n = days.size();

	vector<int> dp(n,INT_MAX);
	vector<int> type = {1,7,30};
	for(int i =0;i< n;i++){
		for(int j = 0;j<3;j++){
			int pre = 0;
			int index = upper_bound(days.begin(), days.end(), days[i] - type[j]) - days.begin()-1;
			if(index>=0) pre = dp[index];
			dp[i] = min(dp[i], pre + costs[j]);
		}
	}
	return dp[n-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
