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
	string s = "bcabc";
	int n = s.size();
	vector<int> count(26,0);
	for(int i = 0;i< n;i++) count[s[i]-'a']=i;
	stack<int> st;
	vector<bool> check(26,false);
	for(int i = 0;i< n;i++){
		if(check[s[i]-'a']) continue;
		while(!st.empty() && count[st.top()]>i && st.top()> (s[i]-'a')){
			check[st.top()] = false;
			st.pop();
		}
		check[s[i]-'a']= true;
		st.push(s[i]-'a');
	}
	string res = "";
	while(!st.empty()){
		res+= ('a' + st.top());
		st.pop();
	}
	reverse(res.begin(), res.end());
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
