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
  vector<int>& nums1;
  vector<int>& nums2;
  int k1;
  int k2;

  int n = nums1.size();
  priority_queue<int, vector<int>, decltype([](int a, int b){return a <b; })> temp;
  for(int i =0;i< n;i++){
    temp.push(abs(nums1[i] - nums2[i]));
  }
  int sum = k1 + k2;
  while(sum>0){
    if(temp.top()>0){
      int top = temp.top();
      temp.pop();
      temp.push(top-1);
    }
    sum--;
  }
  long long res = 0;
  while(!temp.empty()){
    int top = temp.top();
    temp.pop();
    res+=1ll* top*top;
  }
  return res;
}

void solve2(){
        vector<int>& nums1;
        vector<int>& nums2;
        int k1;
        int k2;
        int n = nums1.size();
        long long k = (long long)k1 + k2; // Tổng số lần có thể thay đổi
        
        int max_diff = 0;
        long long sum_diff = 0; // Tổng các độ lệch
        
        vector<long long> count(100005, 0); 
        
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            max_diff = max(max_diff, diff);
            sum_diff += diff;
        }
        
        if (sum_diff <= k) return 0;
        for (int d = max_diff; d > 0 && k > 0; d--) {
            if (count[d] > 0) {
                long long reduce = min(k, count[d]); 
                
                count[d] -= reduce;
                count[d - 1] += reduce;
                k -= reduce; // Trừ đi số thao tác đã dùng
            }
        }
        long long res = 0;
        for (long long d = 1; d <= max_diff; d++) {
            if (count[d] > 0) {
                res += count[d] * d * d;
            }
        }
        return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
