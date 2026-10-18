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
  stack<char> st;
  string convert = "";
  for(int i = 0;i< n;){
    if(s[i]=='('){
      convert +=s[i];
      i++;
    } else{
      if(i+1<n && s[i+1]==')'){
        convert +=']';
        i+=2;
      }else {
        convert+='}';
        i++;
      }
    } 
  }
  int m = convert.size();
  int res = 0;
  for(int i =0;i< m;i++){
    if(convert[i]=='(') st.push('(');
    else{
      if(convert[i]==']' && !st.empty() && st.top()=='(') st.pop();
      else if(convert[i]=='}' && st.empty() && st.top()=='(') {st.pop;res+=1;}
      else st.push(convert[i]);
    }
  }
  while(!st.empty()){
    if(st.top()=='(' || st.top()=='}') res+=2;
    else res+=1;
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
