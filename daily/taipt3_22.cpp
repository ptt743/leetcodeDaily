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
	vector<int> nums={10,10,10};
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int left = 0;
	int ans =0;
	for(int right = 0;right<=n ; right++){
		if( right < n &&  nums[right] == nums[left] && right - left +1 <= nums[left]+1){
			
		} else {
			ans += max(right - left, nums[left]+1);
			left = right;
		}
	}
	cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
