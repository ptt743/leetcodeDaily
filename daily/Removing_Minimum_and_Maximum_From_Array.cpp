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
  int minVal = INT_MAX;
  int maxVal = INT_MIN;
  for(int i = 0;i< n;i++){
    minVal = min(minVal, nums[i]);
    maxVal = max(maxVal, nums[i]);
  }
  pair<int,int> s;
  for(int i = 0;i< n;i++){
    if(nums[i]== minVal) s.first = i;
    if(nums[i]==maxVal) s.second = i;
  }
  if(s.second < s.first ) swap(s.first, s.second);
  return min(s.first+1 + n - s.second, min(s.second+1, n - s.first));
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
