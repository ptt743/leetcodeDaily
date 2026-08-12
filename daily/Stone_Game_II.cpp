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
  vector<int> piles;
  int n = piles.size();
  vector<int> suffix(n,0);
  suffix[n-1] = piles[n-1];

  for(int i = n-2;i>=0;i--){
    suffix[i] = suffix[i+1] + piles[i];
  }

  if(n==0) return 0;
  vector<vector<int>> memo(n, vector<int>(n,-1));
  function<int(int,int)> dfs = [&](int index, int m){
    if(index == n ) return 0;
    if(index + 2*m>=n) return suffix[index];
    if (memo[index][m] != -1) {
            return memo[index][m];
    }
    int minOpponentStones = INT_MAX;
    for (int X = 1; X <= 2 * m; X++) {
            int opponentStones = dfs(index + X, max(m, X));
            minOpponentStones = min(minOpponentStones, opponentStones);
    }
    memo[index][m] = suffix[index] - minOpponentStones;
    return memo[index][m];

  };
  return dfs(0,1);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
