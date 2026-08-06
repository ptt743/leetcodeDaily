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
  int n;
  int k;
  vector<vector<int>>& invocations;
  vector<vector<int>> adj(n, vector<int>());
  for(vector<int> item : invocations){
    adj[item[0]].push_back(item[1]);
  }
  vector<bool> visited(n)
  function<void(int)> dfs = [&](int s){
    visited[s] = true;
    for(int u : adj[s]){
      if(!visited[u]){
        dfs(u);
      }
    }
  };
  dfs(k);
  bool check = false;
  vector<int> res ;
  for(int i =0;i< n;i++){
    if(visited[i]==false){
      res.push_back(i);
      for(int u : adj[i]){
        if(visited[u]){
          check = true;
        }
      }
    }
  }
  if(check){
    for(int i =0;i< n;i++){
      if(visited[i]){
        res.push_back(i);
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
