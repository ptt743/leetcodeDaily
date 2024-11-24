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
	vector<int> nums={1,2,1,3,5,6,4};
	int n = nums.size();
	int left = 0, right = n-1;
	while(left<=right){
		int mid = (left + right)/2;
		if(mid<n-1 && nums[mid]< nums[mid+1]){
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	cout<< left <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
