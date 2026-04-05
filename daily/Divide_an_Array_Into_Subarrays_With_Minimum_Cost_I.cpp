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
	vector<int> nums;
	int n = nums.size();
	priority_queue<int,vector<int>, decltype([](int a, int b){return a> b;})> pq;
	for(int i =1;i< n;i++) pq.push(nums[i]);

	int count = 2;
	int res = nums[0];
	while(count>0){
		res += pq.top();
		pq.pop();
		count--;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
