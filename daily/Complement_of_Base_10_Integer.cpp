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
	if(n==0)return 1;
	int res = 0;
    	int len =0;
	while(n!=0){
		int t = n%2;
		n/=2;
        t = (t==1)?0:1;
		res = (t<<len)|(res);
        len++;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
