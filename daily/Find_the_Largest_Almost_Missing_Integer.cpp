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
  unordered_map<int,int> mp;
  for(int i =0;i< n;i++){
    mp[nums[i]]++;
  }
  int res = INT_MIN;
  if(mp[nums[0]]==1) res = max(res, nums[0]);
  if(mp[nums[n-1]]==1) res = max(res, nums[n-1]);
  if(k==n) for(int i = 0;i< n;i++) res = max(res, nums[i]);
  if(k==1) for(int i = 0;i< n;i++) if(mp[nums[i]]==1) res = max(res, nums[i]);
  return (res==INT_MIN)?-1:res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
