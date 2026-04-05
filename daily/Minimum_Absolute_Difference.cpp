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

	sort(nums.begin(), nums.end());
	int minVal = INT_MAX;
	for(int i = 1;i< n;i++){
		minVal = min(nums[i] - nums[i-1], minVal);
	}
	vector<vector<int>> res;
	for(int i =1;i< n;i++){
		if(nums[i] - nums[i-1] == minVal) res.push_back({nums[i-1], nums[i]});
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
