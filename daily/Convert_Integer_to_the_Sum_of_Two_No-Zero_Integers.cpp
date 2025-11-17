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
	for(int i =1;i<n;i++){
		int a = i;
		int b= n - i;

		string tempa = to_string(a);
		string tempb = to_string(b);
		bool check = true;
		for(int k = 0;k< tempa.size();k++) 
			if(tempa[k]=='0') check = false;
		for(int k = 0;k< tempb.size();k++)
			if(tempb[k]=='0') check = false;

		if(check) return {a,b};
	}
	return {0,0};
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
