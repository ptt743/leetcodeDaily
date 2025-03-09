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
	int n = 6;
	int k = 5;
	vector<int> dp(n);
	dp[0] = 0;
	for(int i =1;i< n;i++){
		dp[i] = (dp[i-1] + k)%(i+1);
		cout<< dp[i]<<endl;
	}
	cout<< dp[n-1] +1;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
