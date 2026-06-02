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
	vector<int>& source;
	vector<int>& target;
	vector<vector<int>>& allowedSwaps;
	vector<int> fa;
    	vector<int> rank;
    	function<int(int)> find=[&](int x) {
        	if (fa[x] != x) {
            		fa[x] = find(fa[x]);
        	}
        	return fa[x];
    	};

    	function<void(int,int)> Union = [&](int x, int y) {
        	x = find(x);
        	y = find(y);
        	if (x == y) return;
        	if (rank[x] < rank[y]) {
            		swap(x, y);
        	}
        	fa[y] = x;
        	if (rank[x] == rank[y]) {
            		rank[x]++;
        	}
    	};

	int n = source.size();
        fa.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
        for (auto& pair : allowedSwaps) {
            Union(pair[0], pair[1]);
        }

	unordered_map<int, unordered_map<int, int>> sets;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets[f][source[i]]++;
        }
	int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
