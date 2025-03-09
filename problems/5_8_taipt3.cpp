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
	string s="abcdef";
	int n = s.size();
	unordered_map<int, stack<int>> mp;
	long long res = 0;
	for(int i =0;i< n;i++){
		int reversed = 0 + (int)('z' - s[i]); 
		if(!mp[reversed].empty()){
			res+= (long long)(i - mp[reversed].top());
			mp[reversed].pop();
		} else {
			mp[int(s[i]-'a')].push(i);
		}
	}
	cout<< res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
