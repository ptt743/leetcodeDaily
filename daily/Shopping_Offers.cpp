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
	vector<int> price;
	vector<vector<int>> special;
	vector<int> needs;
	int n = price.size();
	int m = special.size();
	map<vector<int>,int> mp;
	function<int(vector<int>&)> dfs = [&](vector<int>&  currNeed){
		int cost =0;
		if(mp.find(currNeed)!=mp.end()) return mp[currNeed];

		for(int i = 0;i<n;i++){
			cost += currNeed[i]* price[i];
		}
		int temp =0;
		for(vector<int> offer: special){
			bool check = true;
			vector<int> need_temp;
			int cost_temp = 0;
			for(int i =0;i< n;i++){
				if(offer[i]> currNeed[i]){
					check = false;
					break;
				}
				need_temp.push_back(currNeed[i] - offer[i]);
			}
			if(check) cost = min(cost,offer[n] + dfs(need_temp));
		}
		mp[currNeed] = cost;
		return cost;
	};
	return dfs(needs);

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
