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
	vector<int> nums = {1,1,1,1};
	int n = nums.size();
	int countOne = 0;
	for(int i =0;i<n;i++) if(nums[i]==1) countOne++;
	if(countOne == n) return n-1;
	stack<int> st;
	vector<int> leftCount(n,0);
	for(int i =0;i< n;i++){
		leftCount[i] = 0;
		if(nums[i]==1) st.push(i);
		else {
			while(!st.empty() && nums[st.top()] != nums[i]) st.pop();
			int left = st.empty()? 0: (st.top()+1);
			leftCount[i] = i - left;
			st.push(i);
		}
	}
	st = stack<int>();
	vector<int> rightCount(n,0);
	for(int i = n-1;i>=0;i--){
		rightCount[i] = 0;
		if(nums[i]==1) st.push(i);
		else {
			while(!st.empty() && nums[st.top()]!= nums[i]) st.pop();
			int right = st.empty()?n-1:( st.top()-1);
			rightCount[i] = right - i;
			st.push(i);
		}
	}
	int res = 0;
	for(int i =0;i< n;i++) res= max( res, leftCount[i] + rightCount[i]);
	cout<< res <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
