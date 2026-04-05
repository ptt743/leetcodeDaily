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
	string s = "101";
	int n = s.size();
	int mod = 1e9+7;

	int left = -1;
	long long result = 0;
	function<long(long long)> cal=[&](long long val){
		long long a = val;
		long long b = (val+1)%mod;
		long long res = ( a*b) %mod;
		return res/2;
	};
	for(int i = 0;i<=n;i++){
		if(i==n || s[i] == '0'){ 
			long long val = i - left -1;
			result += cal(val);
			left = i;
		}
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
