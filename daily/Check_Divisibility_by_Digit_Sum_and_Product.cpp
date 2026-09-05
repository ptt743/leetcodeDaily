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
  int t = n;
  int sum = 0;
  int prod = 1;
  while(t>0){
    int temp = t%10;
    t=t/10;
    sum+= temp;
    pro*=temp;
  }
  return n%(sum+ pro)==0;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
