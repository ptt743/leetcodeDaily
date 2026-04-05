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
	vector<int> nums;
	int k;
	int n = nums.size();
	vector<int> pre(n,0);
	int left = -1;
	bool check = true;
	for(int  i =0;i< n-1;i++){
		if(nums[i]==1){
			if(left!=-1 && (i - left-1<k)){
				check = false;
				break;
			}
			left = i;
		}
	}
	int right = n;
	for(int  i =n-1;i>=0;i--){
		if(nums[i]==1){
			if(right!=n && (right - i -1<k)){
				check = false;
				break;
			}
			right = i;
		}
	}
	return check;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
