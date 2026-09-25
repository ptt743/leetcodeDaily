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
  vector<int> rec1;
  vector<int> rec2;
  bool left = rec1[2] <= rec2[0];
  bool right = rec1[0] >= rec2[2];
  bool top = rec1[1] >= rec2[3];
  bool bottom = rec1[3] <= rec2[1];
  return !(left || right || top || bottom);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
