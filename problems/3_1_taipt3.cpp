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
bool solve(){
	vector<int> nums={1,0,1,1,1};
	int target=0;
	int n= nums.size();
	int left = 0, right = n-1;
	while(left<=right){
		int mid = (left+ right)/2;
		if(nums[mid]==target) {return true;}
		if(nums[left]==nums[right] && nums[right]== nums[mid]){
			left++;
			right--;
			continue;
		}
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
	return false;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
