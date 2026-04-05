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
	int target;
	int n = nums.size();

	unordered_map<int,int> mp;
	for(int i =0;i< n;i++){
		if(mp.find(target - nums[i])!= mp.end()){
			return {mp[target-nums[i]], i};
		}
		mp[nums[i]] = i;
	}
	return {0,0};
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
