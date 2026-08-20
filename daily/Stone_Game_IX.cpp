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
  vector<int> stones;
  int counts[3] = {0, 0, 0};
  for(int stone : stones) {
            counts[stone % 3]++;
        }
        
        int c0 = counts[0];
        int c1 = counts[1];
        int c2 = counts[2];
        
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        } else {
            return std::abs(c1 - c2) > 2;
  }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
