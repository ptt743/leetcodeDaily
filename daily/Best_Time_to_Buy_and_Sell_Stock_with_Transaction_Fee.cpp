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
	vector<int> prices;
	int fee;
	int n = prices.size();

	vector<int> empty = vector<int>(n,0);
	vector<int> hold = vector<int>(n,0);
	hold[0] = prices[0];
	for(int  i = 1;i< n;i++){
		empty[i] = max( empty[i-1], hold[i-1] + prices[i] - fee);
		hold[i] = max(hold[i-1], empty[i-1] - prices[i]);
	}
	return empty[n-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
