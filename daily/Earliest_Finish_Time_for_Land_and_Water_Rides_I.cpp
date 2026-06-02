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
	vector<int> a;
	vector<int> at;
	vector<int> b;
	vector<int> bt;

	int n= a.size();
	int m = b.size();
	int minVal = INT_MAX;
	for(int i = 0; i< n;i++){
		for(int j = 0;j< m;j++){
			int endL = a[i] + at[i];
			int endW = b[j] + bt[j];
			minVal = min(minVal, min(max(endL, b[j]) + bt[j], max(endW, a[i])+ at[i]));
		}
	}
	return minVal;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
