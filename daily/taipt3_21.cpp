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
	vector<int> nums ={1,7,9,2,5};
	int lower = 11;
	int upper = 11;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int count = 0;
	for(int i =0;i< n;i++){
		int left = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]) - nums.begin();
		int right = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]) - nums.begin();
		if( right >= left ) count += right - left;
	}
	cout<< count <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
