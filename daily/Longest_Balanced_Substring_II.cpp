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
	int n= s.size();
	int len = 1;
	int left = 0;
	for(int i =1;i< n;i++){
		if(s[i]== s[i-1]){
			len = max(len, i - left+1);
		} else left = i;
	}
	function<void(char, char, char)> diffe = [&](char a, char b, char exclude){
		unordered_map<int, int> mp;
        mp[0] = -1;
		int diff =0;
		for(int i =0;i<n;i++){
			if(s[i] == exclude){
				mp.clear();
				mp[0] = i;
				diff =0;
			} else {
				if(s[i]==a) diff++;
				if(s[i]==b) diff--;
				if(mp.find(diff)!=mp.end()){
					len = max(len, i - mp[diff]);
				}else {
					mp[diff] = i;
				}
			}
		}
	};
	diffe('a','b', 'c');
	diffe('b','c', 'a');
	diffe('a', 'c', 'b');
	
	map<pair<int,int>,int> mp2;
    mp2[{0,0}]=-1;
	int ca=0, cb=0, cc=0;
	for(int i = 0;i< n;i++){
		if(s[i]=='a') ca++;
		if(s[i]=='b') cb++;
		if(s[i]=='c') cc++;
		pair<int,int> state = make_pair(cb - ca, cc - cb);
		if(mp2.find(state)!=mp2.end()){
			len = max( len, i - mp2[state]);
		}else {
			mp2[state] = i;
		}
	}
	return len;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
