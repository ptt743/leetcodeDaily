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
  string s;
  int n = s.size();
  int left = 0;
  vector<int> count(26,0);
  int res = 0;
  for(int i =0;i< n;i++){
    count[s[i]-'a']++;
    while(left <=i && count[nums[i]-'a']>2){
      count[s[left]-'a']--;
      left++;
    }
    res = max( res, i-left+1);
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
