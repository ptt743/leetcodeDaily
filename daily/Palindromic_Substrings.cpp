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
	int res = 0;
	for(int i = 0;i< n;i++){
		// even 
		int left = i;
		int right = i+1;
		int count1 = 0;
		while(left>=0 && right < n && s[left]==s[right]){
			count1++;
			left--;
			right++;
		}
		left=i;
		right=i;
		int count2 = 0;
		while(left>=0 && right < n && s[left]==s[right]){
			count2++;
			left--;
			right++;
		}
		res+= count1 + count2;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
