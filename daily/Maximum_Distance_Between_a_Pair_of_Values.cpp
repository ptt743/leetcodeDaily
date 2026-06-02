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

	int n1 = nums1.size();
	int n2= nums2.size();

	function<int(int)> BS=[&](int val){
		int left = 0;
		int right = nums1.size()-1;
		while( left<=right){
			int mid = (left + right)/2;

			if(nums1[mid] > val) left = mid+1;
			else right = mid-1;
		}
		return left;
	};
	int dis  = 0;
	for(int i =0;i< n2;i++){
		int index = BS(nums2[i]);
		if( index != n1 && index < i){
			dis = max( dis, i - index);
		}
	}
	return dis;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
