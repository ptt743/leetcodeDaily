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
  vector<int> nums1;
  int n = nums1.size();
  set<int> odd, even;
  for(int item : nums1){
    if(item%2==0) even.insert(item);
    else odd.insert(item);
  }
  if(even.size()==0 || odd.size()==0) return true;
  bool checkeven = true;
  bool checkodd = true;
  for(int i = 0;i<n;i++){
      auto it = odd.lower_bound(nums1[i]);
      if(it==odd.begin() && *it >= nums1[i] && nums1[i]%2==0) checkeven = false;
      if(it==odd.begin() && *it >= nums1[i] && nums1[i]%2!=0) checkodd = false;
  }
  return (checkodd || checkeven);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
