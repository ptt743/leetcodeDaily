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
	vector<int>& nums;
	vector<int>& queries;
	int n = nums.size();
	int m = queries.size();

	map<int, vector<int>> mp;

	for(int i =0;i< n;i++){
		mp[nums[i]].push_back(i);
	}
	vector<int> res(m,-1);
	for(int i =0;i< m;i++){
		int index = queries[i];
		int val = nums[index];
		int len = mp[val].size();
		if(len<2) continue;
		int it = lower_bound(mp[val].begin(), mp[val].end(), index) - mp[val].begin();
		if(it ==len-1){
			res[i] = min( mp[val][0] + n- mp[val][it], mp[val][it] - mp[val][it-1]);
			continue;
		}
		if(it ==0){
			res[i] = min( mp[val][0]  + n - mp[val][len-1], mp[val][it+1] - mp[val][it]);
			continue;
		}
		if(len<3) continue;
		res[i] = min(mp[val][it+1] - mp[val][it], mp[val][it] - mp[val][it-1]);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
