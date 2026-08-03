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

  int left = -1;
  vector<int> temp;
  int count =-1;
  for(int i = 0;i<=n;i++){
    if(i!=n && s[i]=='0'){
      continue;
    } else {
      count++;
      if(i-left -1>0){
        int c = i - left-1;
        temp.push_back(i - left-1);
      }
      left = i;
    }
  }
  int maxVal = 0;
  for(int i = 0;i< temp.size();i++){
      if(i+1<temp.size()){
          maxVal = max(maxVal, temp[i] + temp[i+1]);
      }
  }
  return count + maxVal;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
