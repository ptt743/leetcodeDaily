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
  stack<char> st;
  for(int i = 0;i< n;i++){
    if(s[i]=='('){
      st.push(s[i]);
    }else {
      if(!st.empty() && st.top()=='(') st.pop();
      else st.push(')');
    }
  }
  return st.size();
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
