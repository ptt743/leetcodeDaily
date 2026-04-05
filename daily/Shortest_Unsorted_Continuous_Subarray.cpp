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
	int left= n, right = 0;
	set<int> st1;
	for(int i = 0;i<n;i++){
		if(st1.upper_bound(nums[i])!=st.end()){
			right = max(right, i);
		}
		st1.insert(nums[i]);
	}
	set<int> st2;
	for(int i= n-1;i>=0;i--){
		if(st2.lower_bound(nums[i])!=st2.begin()){
			left = min(left, i);
		}
		st2.insert(nums[i]);
	}
	int res = 0;
	if(right > left) res = right - left +1;
	return res;
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
