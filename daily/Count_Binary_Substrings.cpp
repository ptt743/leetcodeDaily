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
	char pre = s[0];
	int left =0;
	int prelen = 0;
	int count = 0;
	for(int i = 0;i< n;i++){
		if(s[i]!= s[left]){
			prelen = i - left;
			left = i;
		}
		if(i - left+1 <= prelen) count++;
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
