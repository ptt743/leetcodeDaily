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
	vector<int> nums={0,2};
	int n = nums.size();
	stack<int> st;
	int result =0;
	for(int item : nums){
		while(!st.empty() && st.top() > item) st.pop();
		if(item ==0) continue;
		if(st.empty() || st.top() < item){
			res++;
			st.push(item);
		}
	}	
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
