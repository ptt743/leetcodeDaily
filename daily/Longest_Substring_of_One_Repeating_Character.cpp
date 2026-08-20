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
  string queryCharacters;
  vector<int>& queryIndices;
  struct Node{
    int max_len, pref_len, suff_len, size;
    char pref_char, suff_char;
  };
  int n = s.size();
  int k = queryIndices.size();
  vector<Node> tree(4*n);
  function<Node(Node, Node)> merge=[&](Node left, Node right) {
        Node res;
        res.size = left.size + right.size;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;

        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }

        res.pref_len = left.pref_len;
        if (left.pref_len == left.size && left.pref_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }

        res.suff_len = right.suff_len;
        if (right.suff_len == right.size && right.suff_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }

        return res;
  };
  function<void(int,int,int)> build=[&](int idx, int l, int r) {
        if (l == r) {
            tree[idx] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = l + (r - l)/2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
  };

  function<void(int,int,int,int,int)> update=[&](int idx, int l, int r, int pos, char c) {
        if (l == r) {
            tree[idx].pref_char = tree[idx].suff_char = c;
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * idx, l, mid, pos, c);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, c);
        }
        tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
  };
  build(1, 0, n - 1);

  vector<int> ans;
  ans.reserve(queryIndices.size());   
  for(int i = 0; i < queryIndices.size(); ++i) {
    update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
    ans.push_back(tree[1].max_len);
  }
  return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
