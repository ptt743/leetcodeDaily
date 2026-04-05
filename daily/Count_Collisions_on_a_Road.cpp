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
	string direct;
        int n = direct.size();

	stack<char> st;
	int res = 0;
	for(int i = n-1;i>=0;i--){
		if(direct[i]=='R'){
			bool check = false;
			bool check2 = false;
			if(!st.empty()) check2 = true;
			while(!st.empty()){
				if(st.top()=='L'){
					if(!check) res+=2;
					else res+=1;
                    			check= true;
					st.pop();
				}
				else if(st.top()=='S') {
					if(!check)res+=1;
					break;
				}
			}
			while(!st.empty()) st.pop();
			if(check2) st.push('S');
			continue;
		} else if (direct[i]=='S'){
			while(!st.empty()){
				if(st.top()=='L')res++;
				st.pop();
			}
		}
		st.push(direct[i]);
	}
	return res;
}

void solve2(){
	string direct;
	int n = direct.size();
	
	int left = 0, right = n-1;
	while(left<n && direct[left]=='L') left++;
	while(right>=0 && direct[right]=='R') right--;
	int result = 0;
	for(int i = left; i<=right;i++){
		if(direct[i]!='S') result++;
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
