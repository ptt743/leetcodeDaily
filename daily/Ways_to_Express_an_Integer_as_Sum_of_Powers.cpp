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
	int n=10;
	int x=2;
	
	int mod = 1e9+7;
	function<int(long long,int)> power=[&](long long a,int b){
		long long result = 1;
		while(b >0){
			if(b&1) result = (result*a)%mod;
			a = (a*a)%mod;
			b>>=1;
		}
		return result;
	};

	vector<int> pw(n+1,0);
	for(int i =0;i<=n;i++) pw[i] = power(i,x);


	vector<vector<int>> mm(301,vector<int>(301,-1));
	function<int(int,int)> dp=[&](int n,int first){
		if(mm[n][first]!=-1) return mm[n][first];
		if(n==0) return 1;
		if(n<0) return 0;
		int total = 0;
		for(int i = first;i <=n;i++){
			if(power(i,x) <= n){
				total += dp(n - pw[i], i+1); 
				total%=mod;
			}
		}
		mm[n][first] = total;
		return total;
	};
	cout<<dp(n,1)<<endl;
}

void solve2(){
	int n = 4;
	int x = 1;
	int mod = 1e9+7;
	function<int(long long,int)> power=[&](long long a,int b){
		long long result = 1;
		while(b >0){
			if(b&1) result = (result*a)%mod;
			a = (a*a)%mod;
			b>>=1;
		}
		return result;
	};
	vector<int> pw(n+1,0);
	for(int i =0;i<=n;i++) pw[i] = power(i,x);

	vector<vector<int>> dp(n+1, vector<int>(n+1,0));

	dp[0][0] = 1;

	for(int j =1;j<=n;j++){
		for(int i = 0;i<=n;i++){
			dp[i][j] = dp[i][j-1];
			if(pw[j]<= i ){
				dp[i][j]+=dp[i- pw[j]][j-1];
			} 
		}
	}

	cout<< dp[n][n]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
