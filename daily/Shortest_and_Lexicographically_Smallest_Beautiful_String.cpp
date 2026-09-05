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
  int k;
  int n = s.size();
  int left = 0;
  int curr  =0;
  string res = "";
  for(int i = 0;i< n;i++){
    if(s[i]=='1') curr++;
    
    while(left <i && (curr>k||(curr==k && s[left]=='0'))){
      if(s[left]=='1')curr--;
      left++;
    }
    if(s[i] =='1' && curr == k){
      string temp =  s.substr(left, i - left+1);
      if(res =="" || (temp.size()==res.size() &&temp< res) || (temp.size()< res.size()))
        res = temp;
    }
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
