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
	vector<int> arr = {2,3,4,0,4,1,0};
	int n = arr.size();

	vector<int> prefix(n,0), suffix(n,0);
	prefix[0] = arr[0];
	for(int i = 1;i< n;i++) prefix[i] = prefix[i-1] + arr[i];
	suffix[n-1] = arr[n-1];
	for(int i = n-2;i>=0;i--) suffix[i] = suffix[i+1] + arr[i];
	int res = 0;
	for(int i = 0;i<n;i++){
		if(arr[i]==0){
			if(prefix[i] == suffix[i]) res +=2;
			if(abs( prefix[i] - suffix[i])==1) res+=1;
		}
	}
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
