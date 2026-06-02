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
	int n = word.size();
	sort(word.begin(), word.end());
    	set<int> st;
    	int count = 0;
   	vector<bool> check(26,false);
    	for(char item : word){
        	st.insert(item -'A');
        	if(st.find((item -'A' - 32))!=st.end()) check[item - 'a'] = true;
    	}
    	for(int i = 0;i< 26;i++) if(check[i]) count++;
    	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
