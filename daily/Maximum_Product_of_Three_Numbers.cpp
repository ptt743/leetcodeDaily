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
  sort(nums.begin(), nums.end());
  int n = nums.size();
  int prefPro = nums[0]*nums[1];
  int suffPro = nums[n-1] * nums[n-2];
  return max(prefPro* nums[n-1], suffPro* nums[n-3]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
