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
	string coridor;
	int n = corridor.size();
	int count = 0;
	for(int i = 0;i< n;i++){
		if(corridor[i]=='S') count++;
	}
	if(count%2!=0 || count ==0) return 0;

	int mod = 1e9 +7;
	long long res = 1;
	int temp = 0;
	int lastIndex =0;
	for(int i = 0;i<n;i++){
		if(s[i]=='S' && temp == 2){
			long long val =  i - lastIndex;
			temp = 1;
			res *= val;
			res%=mod;
		} else if ( s[i]=='S'){
			temp++;
		}
		if( s[i]=='S') lastIndex = i;
	}
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
