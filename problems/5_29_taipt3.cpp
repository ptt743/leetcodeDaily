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
	vector<int> nums={1,1,2,3,4,5};
	int n = nums.size();
	int k = 4;
	int x = -1;
	priority_queue<pair<int,int>, vector<pair<int,int>> , function<bool(pair<int,int>, pair<int,int>)>> 
	pq([&](pair<int,int> a, pair<int,int> b)
	{return (a.first < b.first) || (a.first == b.first && a.second < b.second);});
	for(int i =0;i< n;i++){
		pq.push(make_pair(abs(nums[i] - x), i));
		while(pq.size()>k) pq.pop();
	}
	vector<int> res;
	while(!pq.empty()){
		res.push_back(nums[pq.top().second]);
		pq.pop();
	}
	sort(res.begin(), res.end());
	for(int item: res) cout<< item<<endl;
}


 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
