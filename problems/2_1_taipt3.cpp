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
	vector<int> nums={4,5,6,7,0,1,2};
	int n = nums.size();
	int left = 0, right = n-1;
	while(left<=right){
		int mid = (right+ left)/2;
		if(nums[mid]<=nums[(mid-1+n)%n]){
			cout<< nums[mid]<<endl;
			break;
		}
		if(nums[mid]<nums[right]){
			right = mid-1;
		} else {
			left =mid+1;
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
