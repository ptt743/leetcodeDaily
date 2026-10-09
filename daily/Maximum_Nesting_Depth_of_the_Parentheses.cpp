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
  stack<char> st;
  int n = s.size();
  int count = 0;
  int res = 0;
  for(int i = 0;i< n;i++){
    if(s[i]=='(') st.push(s[i]), count++;
    if(s[i]==')'){
      if(st.top()=='('){
        st.pop();
        count--;
      }else {
        st.push(')');
      }
    }
    res = max(res, count);
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
