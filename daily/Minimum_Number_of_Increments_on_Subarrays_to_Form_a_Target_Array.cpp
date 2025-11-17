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
	
	struct node{
		int val;
		int index;
	};

	struct segment{
		int n;
		vector<node> sg;
		segment(vector<int>& a){
			int n =  a.size();
			sg = vector<node>(4*n + 4, {INT_MAX,-1});
			build(1,0,n-1,a);
		}

		static node combine(node& a, node& b){
			if(a.val> b.val) return b;
			if(b.val> a.val) return a;
			if(a.index !=-1 && b.index!=-1 ) return (a.index< b.index)?a:b; 
			return (a.index!=-1)?a:b;
		}

		void build(int index, int left, int right, vector<int>& arr){
			if(left == right){
				sg[index] = {arr[left],left};
				return;
			}
			int mid = (left + right)/2;
			build(index*2, left, mid,arr);
			build(index*2+1, mid+1, right,arr);
			sg[index] = combine(sg[index*2], sg[index*2+1]);
		}

		node query(int index, int left, int right, int l ,int r){
			if(left>= l && right <= r){
				return sg[index];
			}
			if(left> r || right < l){
				return {INT_MAX,-1};
			}
			int mid = ( left + right)/2;
			node a = query(index*2, left, mid, l,r);
			node b = query(index*2+1, mid+1, right, l,r);
			return combine(a,b);
		}
	};
	
	vector<int> target={1,2,3,2,1};
	int n = target.size();
	segment sg(target);
	function<int(int,int, int)> count=[&](int left, int right, int base){
		if(left>right) return 0;
		node temp = sg.query(1, 0,n-1, left, right);
		int cost = temp.val - base;
		cost += count(left, temp.index-1, temp.val);
		cost += count(temp.index +1, right, temp.val);

		return cost;
		
	};
	return count(0,n-1,0);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
