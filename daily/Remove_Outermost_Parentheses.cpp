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

  int deep = 0;
  string result = "";
  for(int i = 0;i< n;i++){
    if(s[i]=='('){
      if(deep!=0) result+= s[i];
      deep++;
    }else {
      deep--;
      if(deep!=0) result+=')';
    }
  }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
