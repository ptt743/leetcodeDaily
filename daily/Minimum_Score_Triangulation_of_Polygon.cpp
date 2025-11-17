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
	vector<int> values;
	int n = values.size();

	map<pair<int,int>,int> mp;
	function<int(int,int)> dp=[&](int i , int j){
		if(i+2>j) return 0;
		if(i+2==j) return values[i]*values[i+1]* values[i+2];
		pair<int,int> key = make_pair(i,j);
		int mincore = INT_MAX;
		if(mp.find(key)==mp.end()){
			for(int k = i+1;k<j;k++){
				mincore = min(mincore, values[i] * values[k]* values[j] + dp(i,k) + dp(k,j));
			}
			mp[make_pair(i,j)] = mincore;
		}
		return mincore;
	}
	return dp(0,n-1);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
