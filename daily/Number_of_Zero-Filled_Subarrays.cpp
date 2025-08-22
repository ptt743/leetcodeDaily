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
	vector<int> nums={0,0,0,2,0,0};
	int n = nums.size();

	stack<int> st;
	int res = 0;
	for(int i =0;i<=n;i++){
		if(i<n && nums[i]==0) continue;
			
		int count = i - ((!st.empty())?st.top():-1) -1;
		if( count>0) res += (count+1)*count/2;
		st.push(i);
	}
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
