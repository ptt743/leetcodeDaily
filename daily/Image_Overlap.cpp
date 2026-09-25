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
  vector<vector<int>> img1;
  vector<vecto<int>> img2;
  int n = img1.size();
  int res = 0;
  for(int i = -n+1;i<n;i++){
    for(int j = -n+1;j< n;j++){
     int count =0; 
      for(int x = 0;x< n;x++){
        for(int y = 0;y < n;y++){
          if(x + i >=0 && x+ i < n && y + j >=0 && y + j < n 
          && img1[x][y]==img2[x+i][y+j] && img1[x][y]==1){
            count++;
          }
        }
      }
      res = max(res, count);
    }
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
