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
	int n;
	vector<int> nums(n,0);
	for(int i = 0;i< n;i++) nums[i] = i+1;
	int count = 0;
	function<void(int)> RC=[&](int left){
		if(left==n){
			count++;
			return;
		}
		for(int i  = left; i< n;i++){
			swap(nums[i], nums[left]);
            if(nums[left]%(left+1)==0 || (left+1)%nums[left]==0){
			    RC(left+1);
            }
			swap(nums[i], nums[left]);
		}
	};
	RC(0);
	return count;
    }

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
