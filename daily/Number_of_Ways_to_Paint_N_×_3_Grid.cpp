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

	int mod = 1e9+7;
	long long col2 = 6;
	long long col3 = 6;
	for(int i =1;i< n;i++){
		long long newcol2 = 3* col2 + 2*col3;
		long long newcol3 = 2*col2 + 2*col3;
		col2 = newcol2; col2%=mod;
		col3 = newcol3; col3%=mod;
	}
	return (col2+ col3)%mod;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
