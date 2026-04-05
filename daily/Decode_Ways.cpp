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
	string s;
	int n = s.size();
	vector<int> dp(n+1,0);
    	dp[0] = 1;
	if(s[0]!='0') dp[1] = 1;
	for(int i = 2;i<=n;i++){
		string temp ;
        temp += s[i-2];
        temp+= s[i-1];
		int val = stoi(temp);
		if(val>=10 && val<27) dp[i] += dp[i-2];
		if(s[i-1]!='0') dp[i] += dp[i-1];
	}
	return dp[n];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
