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
	int numop;

	int n = nums.size();
	sort(nums.begin(), nums.end());

	int left = nums[i] - k;
	int right = nums[n-1] + k;
	int res = 0;

	for(int i = left ; i<=right;i++){
		int key = i;



		int indexr = upper_bound(nums.begin(), nums.end(), key) - nums.begin();
		int indexl = lower_bound(nums.begin(), nums.end(), key) - nums.begin();

		int indexr1 = upper_bound(nums.begin(), nums.end(), key + k) - nums.begin();
		int indexl1 = lower_bound(nums.begin(), nums.end(), key - k) - nums.begin();
		
		int countrange = indexr1 - indexl1;
		int countkey = indexr - indexl;
		

		res = max(res, min(countrange - countkey,k) + countkey);
	}
	cout<< res <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
