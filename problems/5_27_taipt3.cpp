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
	vector<int> nums={3,3,7,7,10,11,11};
	int n = nums.size();
	if(n==1){
		cout<<nums[0];
		return;
	}
	int left = 0, right = n-1;
	while(left <=right){
		int mid = (left + right)/2;
		if((mid >0 && mid <n-1 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
		   ||(mid ==0 && nums[mid]!=nums[mid+1])
		   ||(mid ==n-1 && nums[mid]!=nums[mid-1])){
			cout<< nums[mid];
			return;
		}
		if(((mid+1)%2==0 && nums[mid]== nums[mid-1]) 
		   ||((mid+1)%2!=0 && nums[mid] == nums[mid+1]))left = mid+1;
		else right = mid-1;
	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
