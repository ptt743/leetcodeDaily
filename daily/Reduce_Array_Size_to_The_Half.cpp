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
	int n = arr.size();

	unordered_map<int,int> mp;
	for(int item : arr) mp[item]++;

	vector<pair<int,int>> nums;
	for(auto it: mp) nums.push_back({it.second, it.first});
	sort(nums.begin(), nums.end());

	int target = n/2;
	int index = nums.size()-1;
	int count =0;
	while(target>0){
		target -= nums[index].first;
		index--;
		count++;
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
