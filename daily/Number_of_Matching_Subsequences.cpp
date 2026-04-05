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
	vector<string> words;
	string s;
	int n = s.size();
	int m = words.size();
	unordered_map<char, vector<pair<int,int>>> mp;
	for(int i =0;i< m;i++){
		mp[words[i][0]].push_back({i,0});
	}
	int count =0;
	for(int i = 0;i< n;i++){
		vector<pair<int,int>> temp = mp[s[i]];
		mp[s[i]].clear();
		for(pair<int,int> item : temp){
			int currIndex = item.second;
			int index = item.first;
			if(++currIndex == words[index].size()){
				count++;
			}else {
				mp[words[index][currIndex]].push_back({index, currIndex});
			}
		}
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
