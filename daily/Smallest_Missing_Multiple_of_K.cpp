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

  set<int> st;
  for(int i =1;i<=101;i++){
      st.insert(i);
  }
  for(int item : nums){
      if(item%k==0){
          st.erase(item/k);
      }
  }
  return *st.begin()*k;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
