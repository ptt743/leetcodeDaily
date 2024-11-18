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
	int target=3;
	int n= nums.size();
	int left = 0, right = n-1;
	while(left<=right){
		int mid = (left+ right)/2;
		if(nums[mid]==target) {cout<< mid<<endl; return;}
		if(nums[left]<=nums[mid]){
			if(target >= nums[left] && target<nums[mid]){
				right = mid-1;
			} else {
				left = mid+1;
			}
		} else {
			if(target <=nums[right] && target >= nums[mid]){
				left = mid+1;
			} else {
				right = mid -1;
			}
				
		}
	}
	cout<<"-1"<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
