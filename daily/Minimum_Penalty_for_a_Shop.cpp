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
	string customers;
	int n = customers.size();

	vector<int> suffix(n+1,0);
	for(int i = n-1;i>=0;i--){
		if(i<n-1) suffix[i]+=suffix[i+1];
		if(customers[i]=='Y') suffix[i]++;
	}
	int count = 0;
	int res = INT_MAX;
	int time = 0;
	for(int i = 0;i<=n;i++){
		if(count + suffix[i] < res){
			res = count + suffix[i];
			time = i;
		}
		if(customers[i]=='N')
			count++;
	}
	return time;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
