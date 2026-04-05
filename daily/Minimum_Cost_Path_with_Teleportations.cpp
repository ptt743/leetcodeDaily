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
	vector<vector<int>> grid;
	int k;
	int n = grid.size();
	int m = grid[0].size();
	vector<pair<int,pair<int,int>>> temp;

	for(int i = 0;i< n;i++){
		for(int j = 0;j< m;j++){
			temp.push_back({grid[i][j],{i,j}});			
		}
	}
	sort(temp.begin(), temp.end(), [&](const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b) {return a.first > b.first;});
	vector<vector<int>> pre_dp(n,vector<int>(m,1e9));
    	pre_dp[0][0] = 0;
	for(int i = 0;i<=k;i++){
		vector<vector<int>> dp(n, vector<int>(m,1e9));
		int minVal = INT_MAX;
		int l = 0;
		if(i==0){
		    dp = pre_dp;
		} else{
		    for(int t = 0;t < temp.size();t++){
			int u = temp[t].second.first;
			int v = temp[t].second.second;
			minVal = min(minVal, pre_dp[u][v]);
			if(t< temp.size()-1 && temp[t].first == temp[t+1].first) continue;
			
			for(int j = l; j<=t;j++){
			    int x = temp[j].second.first;
			    int y = temp[j].second.second;
			    dp[x][y] = min(dp[x][y], minVal);
			}        
			l = t+1;
		    }
		}

		for(int u = 0;u< n;u++){
			for(int v = 0; v< m;v++){
				int top = (u-1>=0)?dp[u-1][v]:(1e9);
				int left = (v-1>=0)?dp[u][v-1]:(1e9);
				dp[u][v] = min(dp[u][v], min(left, top) + grid[u][v]);
			}
		}
		pre_dp = dp;
	}
	return pre_dp[n-1][m-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
