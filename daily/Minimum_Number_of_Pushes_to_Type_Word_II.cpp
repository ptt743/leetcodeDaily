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
  string word;
  int n = word.size();
  map<char,int> mp;
  for(char item : word){
    mp[item]++;
  }
  int count = mp.size();
  vector<int> temp;
  for(auto& item : mp){
    temp.push_back(item.second);
  }
  sort(temp.begin(), temp.end(), [](int a, int b) { return a > b; });
  for(int i =1;i<temp.size();i++) temp[i]+= temp[i-1];
  int res = 0;
  int t = 1;
  int left = -1;
  while(count > 0){
    int c = (count>=8?(8):(count));
    //cout<< temp[left] <<endl;
    res+= (temp[left + c] - ((left>=0)?temp[left]:0))*t;
    left = left + c;
    count-=8;
    t+=1;
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
