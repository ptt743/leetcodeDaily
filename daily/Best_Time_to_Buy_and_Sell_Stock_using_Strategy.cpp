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
	vector<int> trag;
	int k;
        int n = prices.size();
	vector<long long> prefix(n+1,0);
	vector<long long> count(n+1, 0);
	long long sum  = 0;
	for(int i =1; i<=n;i++){
		prefix[i] = prefix[i-1] + trag[i-1] * prices[i-1];
		sum+= prices[i-1] * trag[i-1];
	}
	for(int i =1;i<=n;i++){
		count[i] = count[i-1] + prices[i-1];
	}
	long long result = sum;
	for(int i =0;i<=n - k;i++){
		long long temp = sum - (prefix[i+k]- prefix[i]);
		temp += count[i+k] - count[i+k/2];
		result = max(result, temp);
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
