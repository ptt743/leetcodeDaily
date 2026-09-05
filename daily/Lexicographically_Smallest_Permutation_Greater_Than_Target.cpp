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
  string target;
  int n = s.size();
  vector<int> count(26, 0);
  for (char c : s) {
      count[c - 'a']++;
  }

  int match_len = 0;
  while (match_len < n && count[target[match_len] - 'a'] > 0) {
      count[target[match_len] - 'a']--;
      match_len++;
  }

  for (int i = min(match_len, n - 1); i >= 0; i--) {
      
      if (i < match_len) {
          count[target[i] - 'a']++;
      }
      for (int c = target[i] - 'a' + 1; c < 26; c++) {
          if (count[c] > 0) {
              string res = target.substr(0, i); // Giữ nguyên tiền tố
              res += (char)(c + 'a');           // Rẽ nhánh ký tự lớn hơn
              count[c]--;

              for (int j = 0; j < 26; j++) {
                  while (count[j] > 0) {
                      res += (char)(j + 'a');
                      count[j]--;
                  }
              }
              return res;
          }
      }
  }

  return "";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
