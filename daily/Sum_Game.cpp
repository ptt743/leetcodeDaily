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
  string num;
  int n = num.size();
  int mid =  n/2;
  int left = 0;
  int leftc = 0;
  for(int i =0;i< mid;i++){
    if(num[i]=='?') leftc++;
    else left += (num[i]-'0');
  }
  int right = 0;
  int rightc = 0;
  for(int i =mid;i< n;i++){
    if(num[i]=='?') rightc++;
    else right += (num[i]-'0');
  }
  int a =0, b =0;
  if(rightc > leftc){
    a = rightc - leftc;
    b = left - right;
  }else {
    a = leftc - rightc;
    b = right - left;
  }
  if( a==0 && b==0) return false;
  if(b<=0 ||(b>0 && 9*a<b)) return true;
  int half =(a+1)/2;
  if(half*9<=b && (9*a- half*9 >=b)) return false;
  return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
