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
	vector<vector<int>> trips;
	int capacity;
	
	int n = trips.size();
	sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int> & b){ return a[1]< b[1]; });
	priority_queue<vector<int>, vector<vector<int>>, decltype([](vector<int>&a, vector<int>&b){ return a[2]>b[2];})>pq;
	int curr = 0;
	for(int i = 0;i<n;i++){
		int time = trips[i][1];
		while( !pq.empty() && pq.top()[2]<=time){
			curr -=pq.top()[0];
			pq.pop();
		}
		if(curr + trips[i][0]>capacity) return false;
		curr+= trips[i][0];
		pq.push(trips[i]);
	}
	return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
