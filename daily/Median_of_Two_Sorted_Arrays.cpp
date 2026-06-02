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
	vector<int>& nums1;
	vector<int>& nums2;
	function<double(vector<int>&, vector<int>&)> exec = [&]( vector<int>& nums1, vector<int>& nums2){
		if(nums1.size() > nums2.size())
			return exec( nums2, nums1);
		int n = nums1.size();
		int m = nums2.size();
		int low  = 0;
		int high = n;
		while( low<=high){
			int partitionX = low + (high - low) / 2;
			int partitionY = (m + n + 1) / 2 - partitionX;
			int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
			int minRightX = (partitionX == n) ? INT_MAX : nums1[partitionX];
		    
			int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
			int minRightY = (partitionY == m) ? INT_MAX : nums2[partitionY];

			if( maxLeftX <= minRightY && maxLeftY <= minRightX){
				if((n+m)%2==0){
					return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0;
				}
				else {
					return (double)max(maxLeftX, maxLeftY);
				}
			}
			else if (maxLeftX > minRightY) {
				high = partitionX - 1;
			}
			else {
				low = partitionX + 1;
			}

		}
		return (double)-1;
	};
	return exec(nums1, nums2);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
