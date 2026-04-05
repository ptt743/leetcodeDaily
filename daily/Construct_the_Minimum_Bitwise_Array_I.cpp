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

	vector<int> ans(n,-1);

	for(int i =0;i< n;i++){
		if(nums[i]%2==0) continue;
		else {
			for(int j =0;j<nums[i];j++){
				if(j|(j+1)==nums[i]){
					ans[i] = j;
					break;
				}
			}
		}
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
