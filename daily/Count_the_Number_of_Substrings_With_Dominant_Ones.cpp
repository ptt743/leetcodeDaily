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

	vector<int> pre(n+1,0);

	for(int i = 0;i< n;i++){
		if(i==0 || ( i>0 && s[i-1]=='0')){
			pre[i+1] = i;
		} else {
			pre[i+1] = pre[i];
		}
	}
	int res = 0;
	for(int i = 0;i<=n;i++){
		int j = i;
		int cnt0 = (s[i-1] == '0');
		while(j>0 && cnt0*cnt0 <= n){
			int cnt1 = ( i - pre[j]) - cnt0;
			if(cnt0*cnt0<= cnt1){
				res += min(j - pre[j] , cnt1 - cnt0* cnt0 +1); 
			}
			j = pre[j];
			cnt0++;
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
