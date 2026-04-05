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
	int p ;
	int n = nums.size();
	map<int,int> mp;
	int sum = 0;
	for(int item : nums)
		sum= (sum+item)%p;
	int remain = sum%p;
    	if(remain ==0) return 0;
	int pref = 0;
	int res = n;
	mp[0] = -1;
	for(int i=0;i<n;i++){
		pref= (pref + nums[i])%p;
		int f  = ( pref - remain + p)%p;
		if(mp.find(f)!=mp.end()){
			res = min(res, i - mp[f]);
		}
		mp[pref] = i;
	}
    	if(res==n) return -1;
	return res;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
