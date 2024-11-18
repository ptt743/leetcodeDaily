#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<int> nums={};
	int target = 0;
	int n = nums.size();
	int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
	right--;
	if(left ==n || (left>=0 && left<n && nums[left]!=target)) left =-1;
	if(right<0 || (right>=0 && right<n && nums[right]!=target)) right =-1;
	cout<< left << " "<<right<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
