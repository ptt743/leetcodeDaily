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
	string source;
	string target;
	vector<string>& original;
	vector<string>& changed;
	vector<int> cost;

	int n = source.size();
	int m = original.size();
	struct trie{
		vector<trie*> arr;
		int id;
		trie(){
            arr = vector<trie*>(26);
			for(int i=0;i< 26;i++){
				arr[i] = nullptr;
			}
			id = -1;
		}
	};
	trie* root = new trie();
	function<int(trie*, string&, int&)> add=[&](trie* node, string& word, int& index){
		for(char item : word){
			int i = item - 'a';
			if(!node->arr[i]){
				node->arr[i] = new trie();
			}
			node = node->arr[i];
		}
		if(node->id ==-1) node->id = ++index;
		return node->id;
	};

	function<void(long long&,long long)> update = [&](long long& x, long long y){
		if(x ==-1 || y<x){
			x = y;
		}
	};

	int p = -1;
	vector<vector<int>> G(2*m , vector<int>(2*m,1e8));

	for(int i = 0;i< 2*m;i++) G[i][i] = 0;
	for (int i = 0; i < m; ++i) {
            int x = add(root, original[i], p);
            int y = add(root, changed[i], p);
            G[x][y] = min(G[x][y], cost[i]);
        }
	for (int k = 0; k <= p; ++k) {
            for (int i = 0; i <= p; ++i) {
                for (int j = 0; j <= p; ++j) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

	vector<long long> f(n, -1);
	for (int j = 0; j < n; ++j) {
	    if (j > 0 && f[j - 1] == -1) {
                continue;
            }
	    long long base = (j == 0 ? 0 : f[j - 1]);
	    if (source[j] == target[j]) {
                update(f[j], base);
            }
	    trie* u = root;
        trie* v = root;
	    for (int i = j; i < n; ++i) {
                u = u->arr[source[i] - 'a'];
                v = v->arr[target[i] - 'a'];
                if (!u || !v) {
                    break;
                }
                if (u->id != -1 && v->id != -1 && G[u->id][v->id] != 1e8) {
                    update(f[i], base + G[u->id][v->id]);
                }
            }

	}
	return f[n-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
