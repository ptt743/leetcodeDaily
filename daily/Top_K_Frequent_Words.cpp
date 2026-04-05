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
	int k;
	int n = words.size();

	map<string,int> mp;
	for(string item : words){
		mp[item]++;
	}
	priority_queue<pair<string,int> , vector<pair<string, int>>, decltype([](pair<string,int> a, pair<string,int> b){
			return a.second < b.second || (a.second == b.second && a.first >  b.first)})> pq;
	for(auto& item : mp){
		pq.push({item->first, item->second});
	}
	vecrtor<string> res;
	for(int i =0;i< k;i++){
		res.push_back(pq.top().first);
		pq.pop();
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
