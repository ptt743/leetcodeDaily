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
	vector<int> nums={2,2,3,4};
	int n = nums.size();
	int count = 0;
	for(int i =0;i< n-2;i++){
		for(int j = i+1;j<n-1;j++){
			for(int k = j+1;k<n;k++){
				if((nums[i] < nums[j] + nums[k]) &&
				   (nums[j] < nums[i] + nums[k]) &&
				   (nums[k] < nums[i] + nums[j]))
				{
					count++;
				}
			}
		}
	}
	cout<< count<< endl;
}

void solve2(){
	vector<int> nums={2,2,3,4};
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int result = 0;
	for(int i =0;i< n-2;i++){
		if(nums[i]==0) continue;
		for(int j = i+1;j<n-1;j++){
			int left  = j+1, right = n-1;
			int target = nums[i] + nums[j];
			while(left<=right){
				int mid = (left + right)/2;
				if(nums[mid] >= target) right = mid-1;
				else left = mid+1;
			}
			if(left-1>j) result += ( left - j -1);
		}
	}
	cout<< result <<endl;
}

void solve3(){
	vector<int> nums = {4,2,3,4};
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int res = 0;
	for(int i =0;i< n-2;i++){
		int k = i+2;
		for(int j = i+1;j<n-1;j++){
			while(k<n && nums[k] < nums[i] + nums[j])k++;
			if(k-1 > j){
				res += (k - j-1);
			}
		}
	}
	cout<< res << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve3();
    return 0;
}
