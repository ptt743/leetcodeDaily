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
	string num;
	int n = num.size();

	stack<int> st;
	for(int i = 0;i< n;i++){
		while(!st.empty() && st.top() > (num[i]-'0') && k>0){
			k--;
			st.pop();
		}
		st.push(num[i]-'0');
	}
	string  res ="";
	while(!st.empty()){
        if(k>0){
            k--;
            st.pop();
            continue;
        }
		res+= '0' + st.top();
        st.pop();

	}
	reverse(res.begin(), res.end());
    string result = "";
    for(int i = 0;i< res.size();i++){
        if(result=="" && res[i]=='0') continue;
        result+= res[i];

    }
    if(result=="") result="0";
    return result;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
