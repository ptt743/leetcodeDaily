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
    int n = nums.size();
  vector<int> suffix(n+1,INT_MAX);
  for(int i = n-1;i>=0;i--){
    suffix[i] = min(suffix[i+1], nums[i]);
  }
  int res = INT_MAX;
  int max_val = INT_MIN;
  for(int i = 0;i< n;i++){
    max_val = max(max_val, nums[i]);
    if(max_val - suffix[i]<=k) res = min( res, i);
  }
  return (res==INT_MAX)?-1:res;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
