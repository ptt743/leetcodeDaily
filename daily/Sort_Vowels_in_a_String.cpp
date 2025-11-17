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
	string s="lEetcOde";
	int n = s.size();
	vector<int> vow;
	set<char> st = {'e', 'u', 'o', 'a', 'i', 'E', 'U', 'O', 'A', 'I'};
	for(int i =0;i< n;i++){
		if(st.find(s[i])!=st.end()){
			vow.push_back(s[i]);
		}
	}
	sort(vow.begin(), vow.end());
	int index = 0;
	for(int i =0;i< n;i++){
		if(st.find(s[i])!=st.end()){
			s[i]= vow[index++];	
		}
	}
	cout<< s <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
