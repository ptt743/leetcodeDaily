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
	while(s.size()>2){
		string temp = "";
		int len = s.size();
		for(int i =0;i< len-1;i++){
			temp+=('0' + ((s[i]-'0') + ( s[i+1] -'0'))%10 );
		}
		s = temp;
	}
	return s[0] == s[1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
