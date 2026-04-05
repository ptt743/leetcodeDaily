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
	vector<int> nums;
	int n = nums.size();
	struct SegmentTree{
		int n;
		vector<int> mn,mx, lazy;
		SegmentTree(int sz){
			n = sz;
			mn = vector<int>(4*n +1,0);
			mx = vector<int>(4*n +1,0);
			lazy = vector<int>(4*n+1,0);
		}

		void push(int index){
			if(lazy[node]!=0){
				int val = lazy[node];
				mn[2*index]+=val;
				mx[2*index]+=val;
				lazy[2*index]+=val;

				mn[2*index+1] += val;
				mx[2*index+1] += val;
				lazy[2*index+1] +=val;
				lazy[node] = 0;
			}
		}

		void update(int index, int start, int end, int l, int r){
			if(start>=l && end <=r){
				mn[index]+=val;
				mx[index]+=val;
				lazy[index]+=val;
				return;
			}
			if(start > r || end < l) return;
			push(index);
			int mid = ( start + end)/2;
			update(index*2, start, mid, l,r);
			update(index*2+1, mid+1, end, l , r);
			mn[index] = min(mn[index*2], mn[index*2+1]);
			mx[index] = max(mx[index*2], mx[index*2+1]);
		}

		int findFirstZero(int index, int start, int end){
			if(mn[index]>0 || mx[index]<0) return -1;
			if(start == end){
				return mn[index]==0?start:-1;
			}
			push(index);
			int mid = ( left + right)/2;
			int left = findFirstZero(index*2, start, mid);
			if(left != -1) return left;
			return findFirstZero(index*2+1, mid+1, end);
		}
	};

	segmentTree sg(n);
	unordered_map<int,int> mp;
	int len = 0;
	for(int i = 0;i< n;i++){
		int val = (nums[i]%2==0)?1:-1;
		int left = (mp.find(nums[i])!=mp.end())?(mp[nums[i]]):-1;
		sg.update(1, 0,n-1, left+1, i);
		int l = sg.findFirstZero(1, 0, n-1);
		if(l!=-1){
			len = max(len,  i - l+1);
		}
		mp[nums[i]] = i;
	}
	return len;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
