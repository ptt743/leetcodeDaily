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
	int k;
        int n = nums.size();

	stack<int> st;
	for(int i = 0;i< n - k+1;i++){
		while(!st.empty() && st.top() > nums[i]) st.pop();
		st.push(nums[i]);
	}
	int count = 1;
	for( int i = n-k+1; i<n;i++){
		while(st.size() > count && st.top() > nums[i]) st.pop();
		st.push(nums[i]);
        	count++;
	}
	vector<int> temp;
	while(!st.empty()){
		temp.push_back(st.top());
		st.pop();
	}
	reverse(temp.begin(), temp.end());
	vector<int> res( temp.begin(), temp.begin() + k);
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
