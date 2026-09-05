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
  vector<string> classroom;
  int energy;
  int n = classroom.size();
  int m = classroom[0].size();
  struct node {
    int x;
    int y;
    int step;
    int energy;
    int mask;
  };

  int start_x = -1, start_y = -1;
  vector<vector<int>> litter(n, vector<int>(m, -1));
  int count = 0;
  for(int i = 0;i< n;i++){
    for(int j = 0;j< m;j++){
      if(classroom[i][j]=='S'){
        start_x = i;
        start_y = j;
      }
      if(classroom[i][j] =='L') litter[i][j] = count++;
    }
  }
  vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(1<< count,-1)));
  queue<node> qq;
  qq.push({start_x, start_y, 0,energy, 0});
  visited[start_x][start_y][0] = energy;
  vector<int> dx = {-1,1,0,0};
  vector<int> dy = {0,0,-1,1};
  while(!qq.empty()){
    node front = qq.front();
    qq.pop();
    for(int t =0;t<4;t++){
      int nx = front.x + dx[t];
      int ny = front.y + dy[t];
      if(nx>=0 && nx<n && ny >=0 && ny <m && classroom[nx][ny]!='X'){
        int mask = front.mask;
        int ene = front.energy-1;
        int step = front.step+1;
        if(classroom[nx][ny]=='R') ene = energy;
        if(classroom[nx][ny]=='L') mask = mask | (1<<litter[nx][ny]);
        if(mask == (1<<count)-1) return step;
        if(ene<=0) continue;; 
        if(visited[nx][ny][mask] < ene){
          visited[nx][ny][mask] = ene;
          qq.push({nx,ny, step, ene, mask});
        }
      }
    }
  }
  return -1;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
