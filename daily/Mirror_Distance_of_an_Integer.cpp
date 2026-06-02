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
	function<int(int)> reverse = [](int a){
		while(a%10==0) a/=10;
		int res = 0;
		while(a>0){
			res = res*10 + a%10;
			a/=10;
		}
		return res;
	};

	return abs(n - reverse(n));
	 
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
