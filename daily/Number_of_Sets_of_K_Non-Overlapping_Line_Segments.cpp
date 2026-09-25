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
  int n, k;
  int mod = 1e9+7;
  vector<vector<int>> dp(n+1, vector<int>(k+1,0));
  vector<int> prefix(k+1,0);
  for(int i = 1;i<=n;i++){
    dp[i][0] = 1;
    for(int j =1;j<=k;j++){
      if(j<=i){
        dp[i][j] = (dp[i-1][j] + prefix[j-1])%mod;
      }
    }
    for(int j = 0;j<=k;j++){
      prefix[j] += dp[i][j];
      prefix[j]%=mod;
    }
  }
  return dp[n][k];
}

void solve2(){
  int mod = 1e9+7;
  function<long(long ,long ,int)> power = [&](long base, long exp, int mod){
        long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
  };
  function<long(long, int)> modInverse=[&](long n, int mod) {
        return power(n, mod - 2, mod);
  };

  int N = n + k - 1;
  int R = 2 * k;      
  if (N < R) return 0;
        
  long num = 1, den = 1;
  for (int i = 0; i < R; i++) {
      num = (num * (N - i)) % MOD;
      den = (den * (i + 1)) % MOD;
  }      
  return (int) ((num * modInverse(den, mod)) % mod);

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
