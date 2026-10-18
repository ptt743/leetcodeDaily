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
  stack<int> st;
  st.push(0);
  for(int i = 0;i< n;i++){
    if(s[i]=='('){
      st.push(0);
    }else {
      int value = st.top();
      st.pop();
      int curr = max(2*value,1);
      st.top()+=curr;
    }
  }
  return st.top();
}
 
void solve2(){
  string s;
  int n = s.size();
  int d = 0;

  for(int i = 0;i<n;i++){
    if(s[i]=='(') d++;
    else {
      d--;
      if(i>=1 && s[i-1]=='('){
        res +=1<<d;
      }
    }
  }
  return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
