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
	vector<int> arr;
	int k;
	int n = arr.size();

	priority_queue<pair<int,int>, vector<pair<int,int>> , decltype([](pair<int,int>a, pair<int,int>b){ return a.first * b.second  < b.first * a.second;})>pq;
	for(int i = 0;i< n;i++){
		for(int j = 0; j< i;j++){
			pq.push({arr[j], arr[i]});
			if(pq.size() > k ) pq.pop();
		}
	}
	return {pq.top().first, pq.top().second}; 

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
