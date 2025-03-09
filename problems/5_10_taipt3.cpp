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
	vector<int> heights={3,2,5,5,2,3};
	int n = heights.size();
	stack<int> st1, st2;
	vector<int> left(n+2,0), right(n+2,0);
	for(int i =0;i< n;i++){
		while(!st1.empty() && heights[i] < heights[st1.top()]) st1.pop();
		int temp = 0;
		if(!st1.empty()) temp = st1.top()+1;
		left[i+1] = left[temp] + (long long)(i+1 - temp)* heights[i];
		st1.push(i);
	}
	for(int i = n-1;i>=0;i--){
		while(!st2.empty() && heights[i] < heights[st2.top()]) st2.pop();
		int temp = n+1;
		if(!st2.empty()) temp = st2.top() +1;
		right[i+1] = right[temp] + (long long)(temp -(i+1)) * heights[i];
		st2.push(i);
	}
	int result =0;
	for(int i =1;i<=n;i++){
		result = max(left[i] + right[i] - heights[i-1], result);
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
