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
  vector<vector<int>> grid;
  int k;
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> temp(n, vector<int>(m,0));

  for(int i =0;i< n;i++){
    for(int j = 0;j < m; j++){
      int remain = m - j;
      int ny = i;
      int nx = j;
      int tk = k;
      if(tk>= remain ){
        tk -= remain;
        ny +=1;
        nx = 0;
      }
      ny += tk/m;
      nx += tk%m;
      ny%=n;
      nx%=m;
      //cout << ny << " "<<nx<<endl;
      temp[ny][nx] = grid[i][j];
    }
  }
  return temp;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
