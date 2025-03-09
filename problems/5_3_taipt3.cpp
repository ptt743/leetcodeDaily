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
struct option{
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a.second > b.second;
	}
};
void solve(){
	vector<int> nums = {1,1,1,2,2,3};
	int k=2;
	int n = nums.size();
	unordered_map<int,int> mp;
	for(int i =0;i< n;i++) mp[nums[i]]++;
	vector<int> res;
	priority_queue<pair<int,int>, vector<pair<int,int>>, option> pq;
	for(const auto& it : mp){
		pq.push( {it.first, it.second});
		if(pq.size()>k) pq.pop();
	}
	while(pq.size()>0){
		res.push_back(pq.top().first);
		pq.pop();
	}

	

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
