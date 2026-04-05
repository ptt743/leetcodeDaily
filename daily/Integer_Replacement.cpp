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
	unordered_map<long long,long long> mp;
	function<long long(long long)> DP = [&](long long n)->long long{
        if(n==1) return 0;
		if(mp.find(index)!=mp.end()) return mp[index];
		
		if(n%2==0){
			long long val =  1+ DP(n/2);
            mp[n] = val;
            return val;
		} else {
            long long val = 2 + min(DP((n-1)/2), DP((n+1)/2));
            mp[n] = val;
			return val;
		}
	};
	return DP(index);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
