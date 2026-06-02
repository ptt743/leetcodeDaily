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
	vector<int>& barcodes;
	int n = barcodes.size();

	unordered_map<int,int> mp;
	priority_queue<pair<int,int>, vector<pair<int,int>>, decltype([](pair<int,int> a, pair<int,int> b){
			return a.second < b.second;
			})> pq;
	for(int i =0;i< n;i++) mp[barcodes[i]]++;

	for(auto & it: mp){
		pq.push({it.first, it.second});
	}
	vector<int> res;
	while(pq.size()>=2){
		pair<int,int> first = pq.top();
		pq.pop();
		pair<int,int> second = pq.top();
		pq.pop();
		res.push_back(first.first);
		res.push_back(second.first);
		first.second--;
		second.second--;
		if(first.second>0) pq.push(first);
		if(second.second>0) pq.push(second);
	}
	if(pq.size()>0) res.push_back(pq.top().first);
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
