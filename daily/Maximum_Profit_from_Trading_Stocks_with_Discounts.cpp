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
#include <tuple>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n;
	vector<int> present;
	vector<int> furture;

	vector<vector<int>> hier;
	int budget;

	vector<vector<int>> adj(n, vector<int>());
	for(vector<int> item : hier){
		adj[item[0]-1].push_back(item[1]-1);
	}

	function<tuple<vector<int>, vector<int>, int>(int)> dfs = [&](int u){
			int cost = present[u];
			int dCost = present[u]/2;
			
			vector<int> dp0 = vector<int>(budget+1,0);
			vector<int> dp1 = vector<int>( budget+1,0);

			vector<int> subProfit0 = vector<int>(budget+1,0);
			vector<int> subProfit1 = vectoe<int>(budget+1,0);

			int uSize = cost;
			for(int v : adj[u]){
				auto[suddp0, subdp1, vSize] = dfs(v);
				uSize +=vSize;	
				for(int i = budget;i>=0;i--){
					for(int sub = 0; sub<= min( vsize, i); sub++){
						subProfit0[i] = max(subProfit0[i], subProfit0[i - sub] + subDp0[sub]);
                        			subProfit1[i] = max(subProfit1[i], subProfit1[i - sub] + subDp1[sub]);
					}
				}
			}
			for (int i = 0; i <= budget; i++) {
				dp0[i] = dp1[i] = subProfit0[i];

				if (i >= dCost) {
				    dp1[i] = max(subProfit0[i],
						 subProfit1[i - dCost] + future[u] - dCost);
				}

				if (i >= cost) {
				    dp0[i] = max(subProfit0[i],
						 subProfit1[i - cost] + future[u] - cost);
				}
			}

		    return {dp0, dp1, uSize};


	};


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
