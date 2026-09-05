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
  vector<int> nums;
  int limit;
  vector<pair<int,int>> arr;
  for(int i = 0;i<n;i++){
    arr.push_back({nums[i],i});
  }
  sort(arr.begin(), arr.end(), [](pair<int,int> a, pair<int,int> b){ return a.first < b.first;});
  int n = nums.size();
  vector<int> res(n,0);
  for(int i = 0;i<n;){
    int j = i+1;
    while(j< n && arr[j].first - arr[j-1].first<= limit)j++;
    vector<int> temp;
    for(int t = i;t<j;t++){
      temp.push_back(arr[t].second);
    }
    sort(temp.begin(), temp.end());
    int left = 0;
    for(int t = i ;t<j;t++){
      res[temp[left++]] = arr[t].first; 
    }
    i = j;
  }
  return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
