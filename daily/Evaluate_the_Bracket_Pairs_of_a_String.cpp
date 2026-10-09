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
  vector<vector<string>>& knowledge;
  unordered_map<string,string> mp;
  for(vector<string> item : knowledge){
    mp[item[0]] = item[1];
  }
  int n = s.size();
  string temp ="";
  char pre = ' ';
  string res = "";
  for(int i = 0;i< n;i++){
    if(s[i]=='('){
         pre = '(';
          continue;
    }
    if(s[i]==')'){
      if(mp.find(temp)!=mp.end()){
        res+= mp[temp];
      } else {
        res +='?';
      }
      temp = "";
      pre=' ';
      continue;
    }
    if(pre!=' ') temp+=s[i];
    else res+=s[i];
  }
  return res; 
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
