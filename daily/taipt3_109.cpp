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
#include <climits>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<int> nums={7,9,5,8,1,3};
	int n = nums.size();
	int k = n/3;

	vector<pair<int, int>> par(n);
	priority_queue<int, vector<int>, greater<int>> pq1;
	int temp = 0;
	for(int i =n-1;i>=0;i--){
		pq1.push(nums[i]);
		temp += nums[i];
		if(pq1.size()>k){
			temp -=pq1.top();
			pq1.pop();
		}
		par[i].second = temp;
	}
	temp =0;
	priority_queue<int> pq2;
	for(int i =0;i< n;i++){
		pq2.push(nums[i]);
		temp += nums[i];

		if(pq2.size()>k){
			temp -= pq2.top();
			pq2.pop();
		}
		par[i].first = temp;
	}
	int minVal = INT_MAX;
	for(int i =n/3;i< n - (n/3)+1;i++){
		minVal = min(minVal, par[i-1].first - par[i].second);
	}
	cout<< minVal <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
