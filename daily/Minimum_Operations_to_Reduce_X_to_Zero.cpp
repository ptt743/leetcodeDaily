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
  int x;
  int n = nums.size();
  int count = 0;
  map<int,int> mp;
  int suffix = 0;
   int res = INT_MAX;
  for(int i = n-1;i>=0;i--){
    count++;
    suffix +=nums[i];
    if(suffix==x) res = min(res, count);
    if(mp.find(suffix)==mp.end()){
      mp[suffix] = count;
    }
  }
  if(suffix<x) return -1;
  int prefix = 0;
  int count2 = 0;
  for(int i = 0;i< n;i++){
    count2+=1;
    prefix+=nums[i];
    if(prefix==x) res = min(res, count2);
    if(mp.find(x - prefix)!=mp.end()){
      res = min(res, count2 + mp[x - prefix]);
    }
  }
  return res==INT_MAX?-1:res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
