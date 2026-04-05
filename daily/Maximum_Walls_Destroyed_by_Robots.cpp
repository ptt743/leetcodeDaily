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
	vector<int>& robots;
	vector<int>& distance;
	vector<int>& walls;

	int n = robots.size();
	vector<pair<long long, long long>> r(n);
	unordered_set<long long> st;
	for(int i =0;i< n;i++){
		st.insert(robots[i]);
		r[i] = {robots[i], distance[i]};
	}
	sort(r.begin(), r.end());
	vector<long long> filtered_walls;
	int gruaranteed_walls = 0;
	for(long long item : walls){
		if(st.count(item)){
			gruaranteed_walls++;
		} else {
			filtered_walls.push_back(item);
		}
	}
	sort( filtered_walls.begin(), filtered_walls.end());

	function<int(long long, long long)> countWalls = [&](long long left, long long right)->int{
		if(left > right) return 0;
		auto it1 = lower_bound(filtered_walls.begin(), filtered_walls.end(),left);
		auto it2 = upper_bound(filtered_walls.begin(), filtered_walls.end(), right);
		return it2 - it1;
	};

	vector<vector<int>> dp(n, vector<int>(2,0));

	long long x0 = r[0].first;
	long long d0 = r[0].second;
	dp[0][0] = countWalls(x0 - d0, x0-1);
	dp[0][1] = 0;

	for(int i = 1; i< n;i++){
		long long pre_x = r[i-1].first;
		long long pre_d = r[i-1].second;
		long long curr_x = r[i].first;
		long long curr_d = r[i].second;

		long long r1_start = pre_x+1;
		long long r1_end = min(curr_x-1, pre_x + pre_d);

		long long r2_start = max(pre_x+1, curr_x - curr_d);
		long long r2_end = curr_x-1;

		int c1 = countWalls(r1_start, r1_end);
		int c2 = countWalls(r2_start, r2_end);
		int c3 = 0;
		if(r1_start <= r1_end && r2_start <= r2_end){
			if(r1_end >= r2_start){
				c3 = countWalls(r1_start, r2_end);
			} else {
				c3 = c1+ c2;
			}
		} else if (r1_start <= r1_end){
			c3  = c1;
		} else if( r2_start <= r2_end){
			c3 = c2;
		}
		dp[i][0] = max(dp[i-1][0] + c2, dp[i-1][1] + c3);
		dp[i][1] = max(dp[i-1][0] + 0, dp[i-1][1] + c1);
	}
	long long last_x = r[n-1].first;
	long long last_d = r[n-1].second;
	int last_r = countWalls(last_x + 1, last_x + last_d);

        int max_walls_from_dp = max(dp[n-1][0], dp[n-1][1] + last_r);

	return max_walls_from_dp + gruaranteed_walls;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
