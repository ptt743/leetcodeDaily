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
#include <climits>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<int> nums={1,1,1,1,1,1,1,1};
	int target = 11;
	int n = nums.size();
	int left = 0, right =0;
	int result = INT_MAX;
	int val = 0;
	for(;right<n;right++){
		val += nums[right];
		while(left<=right && val>=target){
			cout<<"-----"<<endl;
			result = min(result, right - left +1);
			val -= nums[left];
            		left++;
		}
	}
	if(result==INT_MAX) result = 0;
	cout<< result<<endl;
}
void solve2(){
	vector<int> nums={1,1,1,1,1,1,1,1};
	int target = 11;
	int n = nums.size();
	vector<int> temp(n+1,0);
	for(int i =0;i< n;i++){
		temp[i+1] = nums[i] + temp[i];
	}
	int result = INT_MAX;
	for(int right =1;right <=n; right++){
		int l  = 1, r = right;
		while(l<=r){
			int mid = (l +r)/2;
			if(temp[right] - temp[mid-1] >= target) l = mid+1;
			else r = mid-1;
		}
		cout<< l <<endl;
		if(l >1) result = min(result, right - l +2);
	}
	if(result==INT_MAX) result = 0;
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
