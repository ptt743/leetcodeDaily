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
  vector<int> arr;
  int n = arr.size();

  function<int(int,int)> gcd= [&](int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
  }
  int minVal = INT_MAX;
  int maxVal = INT_MIN;
  for(int i = 0;i< n;i++){
    minVal = min(minVal, arr[i]);
    maxVal = max(maxVal, arr[i]);
  }
  return gcd(minVal, maxVal);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
