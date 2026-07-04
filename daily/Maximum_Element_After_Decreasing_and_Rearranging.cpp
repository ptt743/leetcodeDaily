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
	vector<int> arr;
	int n = arr.size();
	sort(arr.begin(), arr.end(),[](int a, int b){ return a < b;});

	if(arr[0]!=1) arr[0] = 1;
	for(int i =1;i<n;i++){
		arr[i] = min( arr[i-1]+1, arr[i]);
	}
	return arr[n-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
