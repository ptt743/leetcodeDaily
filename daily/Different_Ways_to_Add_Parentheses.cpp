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
	unordered_map<string,vector<int>> mp;
	function<vector<int>(string&)> RC =[&](string& segment){
		if(mp[segment]!=0) return mp[segment];

		int len = segment.size();
		vector<int> res;
		for(int i =0;i< len;i++){
			char c = segment[i];
			if(c=='+' || c=='-' || c=='*'){
				string left = segment.substr(0,i);
				string right = segment.substr(i+1);
				vector<int> a = RC(left);
				vector<int> b=  RC(right);
				for(int item1: a){
					for( int item2: b){
						if(c=='+') res.push_back(item1 + item2);
						if(c=='-') res.push_back(item1 - item2);
						if(c=='*') res.push_back(item1*item2);
					}
				}
			}
		}
		if(res.empty()) res.push_back(stoi(segment));
		return res;
	}
	vector<int> result = RC(s);
	return result.size();
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
