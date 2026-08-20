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
  vector<vector<int>>& reservedSeats;
   sort(reservedSeats.begin(), reservedSeats.end(), [](vector<int>& a, vector<int>&b){ return (a[0]< b[0])||(a[0]==b[0] && a[1]<b[1]);});
  int k = reservedSeats.size();
  int res =0;
  for(int i =0;i< k;){
    int curr = reservedSeats[i][0];
    int pre = 0;
    while(i<k && reservedSeats[i][0]== curr){
      int temp = reservedSeats[i][1] - pre-1;
      if(temp>=8  && reservedSeats[i][1]==10){
        res += 2;
      }else if(temp>=4  && ((pre<2  && reservedSeats[i][1]>=6)||(pre <4 && reservedSeats[i][1]>7) || (pre <6 && reservedSeats[i][1]>9))){
        res += 1;
      }
      pre = reservedSeats[i][1];
      i++;
    }
    if(9 - pre >=4){
         res +=(9- pre)/4;
    }
    n--;
  }
  res +=2*n;
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
