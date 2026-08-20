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

  vector<pair<int,int>> count(31,{0,0});
  for(int i = 0;i< n;i++){
    int c = 0;
    int temp = nums[i];
    while(temp>0){
      int t = temp%2;
      temp= temp/2;
      if(t)count[c].first++;
      else count[c].second++;
      c++;
    }
  }
  int maxValue = 0;
  for(int i=0;i<31;i++){
    if(count[i].first%2!=0) maxValue = max( maxValue , n);
    else if(count[i].first>0) maxValue = max(maxValue, n-1);
  }
  return maxValue;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
