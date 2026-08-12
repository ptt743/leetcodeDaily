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
  string word1;
  string word2;

  int n = word1.length();
  int m = word2.length();
  
  vector<int> match_len(n + 1, 0);
  
  int j = m - 1;
  for (int i = n - 1; i >= 0; --i) {
      if (j >= 0 && word1[i] == word2[j]) {
          match_len[i] = match_len[i + 1] + 1; // Có khớp, tăng độ dài
          j--;
      } else {
          match_len[i] = match_len[i + 1];     // Không khớp, kế thừa giá trị bên phải
      }
  }
  
  vector<int> ans;
  bool changed = false; // Cờ kiểm tra xem đã dùng quyền thay đổi ký tự chưa
  j = 0; // Đặt lại con trỏ j để duyệt word2 từ đầu
  
  for (int i = 0; i < n; ++i) {
      if (j == m) {
          break; // Nếu đã gom đủ số lượng ký tự thì dừng sớm
      }
      if (word1[i] == word2[j]) {
          ans.push_back(i);
          j++;
      } 
      else if (!changed && match_len[i + 1] >= m - 1 - j) {
          ans.push_back(i);
          changed = true; // Đánh dấu là đã mất quyền thay đổi
          j++;
      }
  }
  if (ans.size() == m) {
      return ans;
  }
  
  return {};
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
