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
  int n = nums.size();

  int minInt = INT_MAX;
  int maxInt = INT_MIN;
  unordered_map<int,bool> mp;
  for(int item : nums){
    minInt = min(minInt, item);
    maxInt = max(maxInt, item);
    mp[item]= true;
  }
  vector<int> res;
  for(int i = minInt; i<maxInt;i++){
    if(mp.find(i)==mp.end()){
      res.push_back(i);
    }
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
