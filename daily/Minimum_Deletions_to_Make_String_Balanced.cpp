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
	vector<int> prefixb(n,0);
	for(int i = 0;i< n;i++){
		if(s[i]=='b') prefixb[i]++;
		if(i>0) prefixb[i]+= prefixb[i-1];
	}
	vector<int> suffixa(n,0);
	for(int i = n-1;i>=0;i--){
		if(s[i]=='a') suffixa[i]++;
		if(i<n-1) suffixa[i]+= suffixa[i+1];
	}
	int res  = INT_MAX;
	for(int i =0;i<=n;i++){
		int left = (i>0)?prefixb[i-1]:0;
		int right = (i<n)?suffixa[i]:0;
		res = min(res, left + right );
	}
	return (res==INT_MAX)?0:res;
}

void solve2(){
	string s;
	int n = s.size();
	int countb=0;
	int del = 0;
	for(int i=0;i< n;i++){
		if(s[i]=='b'){
			countb++;	
		} else {
			del = min(del+1, countb); 
		}
	}
	return del;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
