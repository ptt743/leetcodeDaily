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
	int k;
	int nunmOper;
	
	int n = nums.size();
	sort(nums.begin(), nums.end());

	int left = nums[0] - k;
	int right = nums[n-1] + k;
	int res = 0;
	vector<int> dx = {-1*(k),0,k};
	for(int i = 0 ; i<n;i++){
		for(int v : dx){
			long long key = nums[i] + v;
			int indexr = upper_bound(nums.begin(), nums.end(), key) - nums.begin();
			int indexl = lower_bound(nums.begin(), nums.end(), key) - nums.begin();
			int indexr1 = upper_bound(num:wqs.begin(), nums.end(), key + k) - nums.begin();
			int indexl1 = lower_bound(nums.begin(), nums.end(), key - k) - nums.begin();
			int countrange = indexr1 - indexl1;
			int countkey = indexr - indexl;
			res = max(res, min(countrange - countkey,numOperations) + countkey);
		}
	}
	return res ;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
