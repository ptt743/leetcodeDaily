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
	string s1;
	string s2;

	if(s1==s2) return true;

	swap(s1[0],s1[2]);
	if(s1==s2) return true;
	swap(s1[1], s1[3]);
	if(s1==s2) return true;
	swap(s1[0], s1[2]);
	if(s1==s2) return true;
	return false;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
