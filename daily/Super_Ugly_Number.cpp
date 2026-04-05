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
	int n;
	vector<int> primes;
	int m= primes.size();

	vector<long long> dp(n+1,INT_MAX);
	vector<int> indices(m,0);
	dp[0] = 1;
	for(int i =1;i<n;i++){
		long long temp = LLONG_MAX;
		for(int j =0;j< m;j++){
			temp = min(temp, dp[indices[j]] * primes[j]);
		}
		for(int j = 0;j< m;j++){
			if(dp[indices[j]] * primes[j] == temp) indices[j]++;
		}
        cout<< temp<<endl;
		dp[i] = temp;
	}
	return dp[n-1];	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
