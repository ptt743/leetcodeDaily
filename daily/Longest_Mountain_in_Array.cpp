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
	if(n<3) return 0;
	vector<int> prefix(n,0);
	for(int i = 1;i< n;i++){
		if(nums[i]> nums[i-1]){
			prefix[i] = prefix[i-1];
		} else prefix[i] = i;
	}
	vector<int> suffix(n, n-1);
	for(int i =n-2;i>=0;i--){
		if(nums[i]> nums[i+1]){
			suffix[i] = suffix[i+1];
		} else suffix[i] = i;
	}
	int ans = 0;
	for(int i =1;i< n-1;i++){
        int temp = suffix[i] - prefix[i]+1;
        if(temp<3 || suffix[i]==i || prefix[i]==i) continue;
		ans = max(ans, temp);
	} 
	return ans;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
