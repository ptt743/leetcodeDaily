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
  vector<int> nums;
  int k;
  int n = nums.size();
  vector<vector<long long>> dp(n, vector<long long>(k,0));
  vector<long long> result(k,0);
  for(int i = 0;i< n;i++){
    dp[i][nums[i]%k]+=1;
    for(int j = 0;j< k;j++){
      if(i>=1){
        dp[i][(1ll*j*nums[i])%k] += dp[i-1][j];
      }
    }
    for(int j = 0;j< k;j++) result[j]+= dp[i][j];
  }
  return result;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
