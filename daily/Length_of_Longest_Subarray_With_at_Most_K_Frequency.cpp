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
  set<pair<int,int>> st;
  unordered_map<int,int> mp;
  int left = 0;
  int res = 0;
  for(int i =0;i< n;i++){
    int pre = (mp.find(nums[i])==mp.end())?0:mp[nums[i]];
    mp[nums[i]]++;
    st.erase(make_pair(pre, nums[i]));
    st.insert(make_pair(pre+1, nums[i]));

    while(left<n &&!st.empty() && st.rbegin()->first>k){
      st.erase(make_pair(mp[nums[left]], nums[left]));
      mp[nums[left]]--;
      if(mp[nums[left]]>0) st.insert(make_pair(mp[nums[left]], nums[left]));
      left++;
    }
    res = max(res, i - left+1);
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
