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
	struct segmentTree{
		vector<int> tree;
		int n;
		segmentTree(int size){
			n = size;
			tree = vector<int>(4*n+4,0);
		}

		void insert(int node, int left,int right, int idx, int value){
			if(left == right){
				tree[node] = value;
				return;
			}
			int mid = ( left + right)/2;
			if(idx<=mid){
				insert(node*2, left, mid, idx, value);
			} else {
				insert(node*2+1, mid+1, right, idx, value);
			}
			tree[node] = max(tree[node*2], tree[node*2+1]);
		}

		int get(int node, int left, int right, int l, int r){
			if(l>=left && r <= right) return tree[node];
			if(r<left || l> right) return 0;
			int mid = (left+right)/2;
			int res = max(get(node*2, left, mid, l,r), get(node*2+1, mid+1, right, l,r));
			return res;
		}
	};




}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
