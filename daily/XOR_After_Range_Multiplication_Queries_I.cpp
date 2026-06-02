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
	vector<vector<int>> queries;

	int n = nums.size();
	int m = queries.size();

	int mod = 1e9 + 7;
	for(int i =0;i< m;i++){
		int l = queries[i][0];
		int r = queried[i][1];
		int k = queries[i][2];
		int v = queries[i][3];
		int begin = l;
		while(begin<=r){
			nums[begin] = (nums[begin]* (long long)v)%mod;
			begin+=k;
		}
	}
	int res = nums[0];
	for(int i =1;i< n;i++){
		res^=nums[i];
	}
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
