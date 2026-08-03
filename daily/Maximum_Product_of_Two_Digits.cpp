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
  vector<int> temp;
  while(n>0){
    int t = n%10;
    n= n/10;
    temp.push_back(t);
  }
  sort(temp.begin(), temp.end());
  return temp[temp.size()-1]* temp[temp.size()-2];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
