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
	vector<int> dp(n,0);
	int ans = nums[0];
	int currMin = nums[0];
	int currMax = nums[0];
    
	for(int i =1;i< n;i++){
		if(nums[i]<0){
			swap(currMin, currMax);
		}
		currMin = min(nums[i], nums[i]* currMin);
		currMax = max(nums[i], nums[i]* currMax);
        ans = max(ans, currMax);
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
