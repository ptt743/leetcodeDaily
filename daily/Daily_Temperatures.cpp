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
	vector<int> temp;

	int n = temp.size();
	stack<int> st;
	vector<int> res(n,0);
	for(int i = n-1;i>=0;i--){
		while(!st.empty() && nums[st.top()]<= nums[i]) st.pop();
		if(!st.empty()){
			res[i] = st.top() - i;
		}
		st.push(i);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
