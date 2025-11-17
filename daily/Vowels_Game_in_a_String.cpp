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
	string s;
	int n = s.size();

	set<int> st = {'u', 'e', 'o', 'a' , 'i'};
	int count = 0;
	for(int i = 0;i< n;i++){
		if(st.find(s[i])!=st.end()) count++;
	}
	if(count==0) return false;
	return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
