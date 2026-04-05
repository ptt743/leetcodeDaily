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
	vector<string> code;
	vector<string> businessLine;
	vector<bool> active;

	int n = code.size();
	vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};
	set<string> st = {"electronics", "grocery", "pharmacy", "restaurant"};
	map<string, multiset<string>> mp;
	
	for(int i = 0;i< n;i++){
		bool check = true;
		if(code[i].empty())
			check = false;

		for(int j = 0;j< code[i].size();j++){
			if( !((code[i][j]>='a' && code[i][j]<='z') || (code[i][j]>='A' && code[i][j]<='Z') ||( code[i][j]>='0' && code[i][j]<='9') || code[i][j]=='_')){
				check = false;
			}
			if(st.find(businessLine[i])==st.end()){
				check = false;
			}
			if(active[i]==false){
				check = false;
			}
		}
		if(check) mp[businessLine[i]].insert( code[i]);
	}
	vector<string> res;
	for(string line : order){
		for(string item : mp[line]){
			res.push_back(item);
		}
	}
	return res;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
