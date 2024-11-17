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
	vector<int> nums={3,1};
	int target=3;
	int n= nums.size();
	int left = 0, right = n-1;
	while(left<= right){
		int mid = (left+ right)/2;
		if(nums[mid]==target){
			cout<<mid<<endl;
			return;
		}
		if(nums[left]<= nums[right]){
			if(nums[mid]<= target) left = mid+1;
			else right = mid-1;
		} else{
			if(target>=nums[left]){
				if(nums[mid]>=nums[left] && nums[mid]<=target){
					left = mid+1;
				} else{ 
					right = mid-1;
				}
			} else {
				if(nums[mid]<=nums[right] && nums[mid]>target){
					right = mid-1;
				} else left = mid+1;
			}
		}
		cout<< left << " "<<right<<endl; 
	}
	if(right==-1 && nums[right]!=target) cout<<"-1"<<endl;
	else cout<< right<<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
