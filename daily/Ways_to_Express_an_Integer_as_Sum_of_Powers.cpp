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
	int n=4;
	int x=1;
	
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
	vector<vector<int>> mm(301,vector<int>(300,-1));
	cout<<"aaaa"<<endl;
	function<int(int,int)> dp=[&](int n,int first){
		if(mm[n][first]!=-1) return mm[n][first];
		if(n==0) return 1;
		if(n<0) return 0;
		int total = 0;
		for(int i = first;i <=n;i++){
			if(power(i,x) <= n){
				total += dp(n - power(i,x), first+1); 
			}
		}
		mm[n][first] = total;
		cout<<n <<" "<<first<<" "<< total<<endl;
		return total;
	};
	cout<<dp(n,1)<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
