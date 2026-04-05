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
	map<pair<int,int>,bool> mp;
	function<bool(int, int)> rc=[&](int index, int open){
		if (open < 0) return false;
		if(index ==n ){
			mp[{index, open}] = (open==0);
			return (open==0);
		}
        if(mp.find({index, open})!=mp.end()){
			return mp[{index, open}];
		}
		bool res =  false;
		if(s[index]=='*'){
			 res = rc(index+1, open-1) || rc(index+1, open) || rc(index+1, open+1);
			 mp[{index, open}] = res;
			 return res;
		}
		res =  rc(index+1, open + (s[index]=='('?1:-1));
		mp[{index,open}] = res;
		return res;
	};
	return rc(0,0);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
