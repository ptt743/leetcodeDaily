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
	vector<vector<int>> fruits={{0,10000}};
	int startPos = 200000;
	int k = 200000;

	int n = fruits.size();
	int maxPos = fruits[n-1][0];
	vector<int> sg(4*maxPos+4,0);

	unordered_map<int,int> mp;
	for(int i =0;i< n;i++) mp[fruits[i][0]] = fruits[i][1];
	function<void(int,int,int)> build=[&](int p, int l, int r){
		if(l==r && mp.find(l)!=mp.end()) sg[p] = mp[l];
		if(l==r) return;
		int mid = (l+r)>>1;
		build(p<<1, l, mid);
		build(p<<1|1, mid+1, r);
		sg[p] = sg[p<<1] + sg[p<<1|1];
	};

	function<int(int,int,int,int,int)> query=[&](int p , int l, int r, int ql, int qr){
		if(l>=ql && r<= qr) return sg[p];
		if( l > qr || r < ql) return 0;

		int mid = (l + r)>> 1;
		return query(p<<1, l, mid,ql,qr) + query(p<<1|1, mid+1, r, ql,qr);
	};
	build(1,0,maxPos);

	int result = 0;
	for(int i =0;i< n;i++){
		int pos = fruits[i][0];
		if(pos< startPos){
			if(startPos - pos>k) continue;
			int temp = (k - 2*(startPos - pos));
			int endP = min(maxPos,startPos + ((temp>0)?temp:0));
			result = max(result,query(1, 0,maxPos, pos, endP));
		} else {
			if(pos - startPos > k) continue;
			int temp = (k - 2*(pos- startPos));
			int startP = max(0,startPos - ((temp>0)?temp:0));
			result = max(result,query(1,0,maxPos, startP, pos));
		}
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
