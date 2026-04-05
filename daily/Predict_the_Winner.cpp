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
	vector<int>nums;
	int n = nums.size();
	int sum =0;
	for(int item: nums) sum+=item;
    map<pair<int,int>,int> mp;
	function<int(int,int)> RC=[&]( int left, int right){
		if(left==right) return nums[left];
        if(left>right) return 0;
        pair<int,int> pr = make_pair(left,right);
        if(mp.find(pr)!=mp.end()) return mp[pr];
		int value = max(nums[left] - RC(left+1, right),nums[right] - RC(left, right-1) );
        mp[pr] = value;
		return value;
	};
	if(RC(0,n-1)>=0) return true;
        return false;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
