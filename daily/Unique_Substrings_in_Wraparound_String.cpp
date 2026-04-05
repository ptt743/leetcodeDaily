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
	int count = 1;
	vector<int> cnt(26,0);
	int res = 1;
    	cnt[s[0]-'a']=1;
	for(int i =1;i< n;i++){
		if((s[i] - s[i-1])==1 || ( s[i]=='a' && s[i-1]=='z')){
			count++;
		}else {
			count=1;
		}
		if(count > cnt[s[i]-'a']){
			res += count - cnt[s[i]-'a'];
			cnt[s[i]-'a'] = count;
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
