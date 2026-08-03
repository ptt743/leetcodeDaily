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
using ll = long long;
const ll INF = 1e18 + 7;

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll res = 1;
    for (int i = 1; i <= min(r, n - r); ++i) {
        __int128 tmp = (__int128)res * (n - i + 1) / i;
        if (tmp > INF) return INF;
        res = (ll)tmp;
    }
    return res;
}

ll get_perms(const vector<int>& cnt, int len) {
    ll res = 1;
    for (int c : cnt) {
        if (!c) continue;
        ll comb = nCr(len, c);
        if (res && comb > INF / res) res = INF;
        else res *= comb;
        len -= c;
    }
    return res;
}
void solve(){
  string s;
  int k ;
  int n = s.size();
  vector<int> cnt(26, 0), half(26, 0);
  string mid = "", left = "";
  int n = 0;

  for (char c : s) cnt[c - 'a']++;
  for (int i = 0; i < 26; ++i) {
      if (cnt[i] % 2) mid += (i + 'a');
      n += (half[i] = cnt[i] / 2);
  }

  if (get_perms(half, n) < k) return "";

  for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 26; ++j) {
          if (!half[j]) continue;
          half[j]--;
          ll p = get_perms(half, n - 1 - i);
          if (k <= p) {
              left += (j + 'a');
              break;
          }
          k -= p;
          half[j]++;
      }
  }
  
  string right = left;
  reverse(right.begin(), right.end());
  return left + mid + right;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
