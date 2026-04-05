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
	vector<int> hours;
	int n = hours.size();

	vector<int> arr(n,0);
	for(int i =0;i< n;i++) 
		if(hours[i]>8) arr[i] =1;
		else arr[i] = -1;

	vector<int> prefix(n+1,0);

	for(int i= 0;i<=n;i++){
		prefix[i] += prefix[i-1] + arr[i];
	}
	stack<int> st;
	for(int i = 0;i<=n;i++){
		if(st.empty() || prefix[st.top()] >= prefix[i]) st.push(i);
	}
	int maxWidth = 0;
	for(int i = n;i>=1;i--){
		while(!st.empty() && prefix[st.top()] < prefix[i]){
			maxWidth = max( maxWidth, i - st.top());
			st.pop();
		}
	}
	return maxWidth;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
