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
	int len = 0;
	for(int i = 0;i<n;i++){
		vector<int> chars(26,0);
		for(int j=i;j>=0;j--){
			chars[s[j] - 'a']++;
			int pre = 0;
			for(int k =0;k<26;k++){
                if(chars[k]==0) continue;
				pre = (pre==0)?chars[k]:((pre!=chars[k])?-1:pre);
			}
			if(pre>0) len = max(len, i - j+1);
		}
	}
	return len;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
