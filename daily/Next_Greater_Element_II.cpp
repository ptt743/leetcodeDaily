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

	vector<int> result(n,-1);

	stack<int> st;
	for(int i = 2*n-1;i>=0;i--){
		while(!st.empty() && nums[st.top()] <= nums[i]){
			st.pop();
		}
		if(!st.empty()) result[i] = nums[st.top()];
		st.push(i);
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
