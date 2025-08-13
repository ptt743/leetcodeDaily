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
	vector<vector<int>> fruits;
	int startPos;
	int k;

	int n = fruits.size();
	int maxPos = fruits[n-1][0];
	vector<int> sg(4*maxPos+1,0);

	unordered_map<int,int> mp;
	for(int i =0;i< n;i++) mp[fruits[i][0]] = fruits[i][1];
	function<void(int,int,int)> build=[&](int p, int l, int r){
		if(l==r && mp[l]!=0) sg[p] = mp[l];
		int mid = (l+r)>>1;
		sg[p] = build(p<<1, l, mid)+ build(p<<1|1, mid+1, r);
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
		if(pos[i]< startPos){
			if(startPos - pos[i]>k) continue;
			int temp = (k - 2*(startPos - pos[i]);

			int endP = startPos + (temp>0)?temp:0;
			int index = upper_bound(pos.begin(), pos.end(), endP) - pos.begin()-1;
			result = max(result, fruits[index][1] - fruits[startPos][1]);	
		} else {
			if(pos[i] - startPos > k) continue;

			int temp = (k - 2*(pos[i]- startPos));

			int startP = startPos - (temp>0)>temp:0;


		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
