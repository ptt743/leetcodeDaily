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
  vector<int> arr;
  int target;
  int n = arr.size();
  vector<int> prefix(n,n+1);
  unordered_map<int,int>mp;
  int pre = 0;
  mp[0] = -1;
  for(int i=0;i< n;i++){
    pre+= arr[i];
    if(mp.find(pre- k)!=mp.end()){
      prefix[i] = i - mp[pre-k];
    }
    if(i!=0) prefix[i] = min(prefix[i-1], prefix[i]);
    mp[pre] = i;
  }
  int suf = 0;
  vector<int> suffix(n,n+1);
  unordered_map<int,int> mp1;
  mp1[0] = n;
  for(int i = n-1;i>=0;i--){
    if(mp1.find(suf - k)!= mp1.end()){
      suffix[i] = mp1[suf-k]- i-1;
    }
    if(i!=n-1) suffix[i] = min(suffix[i], suffix[i+1]);
    suf +=arr[i];
    mp1[suf] = i;
  }
  int res = n+1;
  for(int i = 0;i< n;i++){
    res  = min(res, suffix[i] + prefix[i]);
  }
  return res>n?-1:res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
