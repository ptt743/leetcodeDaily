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
	vector<vector<int>> events;
	int n = events.size();

	sort(events.begin(), events.end());
	struct option{
		bool operator()(pair<int,int> a, pair<int,int> b){
			return a.first > b.first ||(a.first == b.first && a.second < b.second);
		}
	};
	int maxValue = 0;
	int sum = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, option> pq;
	for(int i = 0;i< n;i++){
		while(!pq.empty() && pq.top().first < events[i][0]){
			pair<int,int> top = pq.top();
			pq.pop();
			maxValue = max(maxValue, top.second);
		}
		sum = max(sum, maxValue + events[i][2]);
		pq.push({events[i][1], events[i][2]});
	}
	return sum;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
