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
	vector<int>& nums;
	int n = nums.size();
	vector<int> suffix(n,INT_MAX);

	unordered_map<int,int> mp1;
	for(int i =n-1;i>=0;i--){
		if(mp1.count(nums[i])){
			suffix[i] = mp1[nums[i]];
		}
		mp1[nums[i]] =i;
	}
	vector<int> prefix(n,INT_MAX);
	unordered_map<int,int> mp2;
	long long res = INT_MAX;
	for(int i = 0;i< n;i++){
		if(mp2.count(nums[i])){
			long long a = mp2[nums[i]];
			long long b = i;
			long long c = suffix[i];
			if(a!=INT_MAX && b != INT_MAX && c!=INT_MAX){
				res = min(res, abs(a - b) + abs(b-c) + abs(a-c));
			}
		}
		mp2[nums[i]] = i;
	}
	return ( res ==INT_MAX)? -1:res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
