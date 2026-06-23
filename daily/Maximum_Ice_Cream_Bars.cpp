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
	vector<int> costs;
	int coins;
	int n = costs.size();
	sort(costs.begin(), costs.end(), [](int a, int b){ return a < b;});
	int left = 0;
	while( coins>0){
		if(left < n && costs[left]<= coins){
			coins-=costs[left];
			left++;
		} else break;
	}
	return left;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
