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
	unordered_map<int,long long> mp;
	unordered_map<int,long long> count;
	for(int i = 0;i< n;i++){
		mp[nums[i]]+=i;
		count[nums[i]]++;
	}
	unordered_map<int,long long> mp2;
	unordered_map<int,long long> count2;
	vector<long long> arr(n,0);
	for(int i =0;i< n;i++){
		
		int left = count2[nums[i]];
		int right = count[nums[i]] - 1- left;
		arr[i] = (long long)i*left + (long long)(-1*i)*right - (long long)mp2[nums[i]] + (long long)(mp[nums[i]] - mp2[nums[i]] - i);
		mp2[nums[i]]+=i;
		count2[nums[i]]++;
	}
	return arr;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
