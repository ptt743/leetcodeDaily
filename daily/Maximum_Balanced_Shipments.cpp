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
	vector<int> weight;
	int n = weight.size();

	stack<int> st;
	set<int> sett;
	int count = 0;
	for(int i = 0;i< n;i++){
		while(!st.empty() && st.top() > nums[i]){
			count++;
			st.clear();
			break;
		}
		if(check)while(!st.empty()) st.pop();
		else st.push(nums[i]);
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
