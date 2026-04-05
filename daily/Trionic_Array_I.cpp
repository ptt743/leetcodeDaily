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

	stack<int> st;
	int pre = -1001;
	int left =0;
	for(int i = 0;i<n;i++){
		if(nums[i]<= pre){
			left = i-1;
			break;
		}
		pre= nums[i];
	}
	int prer = 1001;
	int right = n-1;
	for(int i = n-1;i>= 0;i--){
		if(nums[i]>= prer){
			right = i+1;
			break;
		}
		prer= nums[i];
	}

	if(left==0 || right ==n-1 || left>=right) return false;
	int premid = 1001;
	for(int i = left; i<=right;i++){
		if(nums[i]>=premid) return false;
		premid = nums[i];
	}
	return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
