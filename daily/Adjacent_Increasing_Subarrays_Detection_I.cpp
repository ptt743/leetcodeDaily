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
	int pre =0;
	int left = 0;
	int count = 1;
	if(k==1) return true;
	for(int i = 1;i< n;i++){
		if(nums[i]<= nums[i-1]){
			left = i;
			pre = count;
			count = 1;
			continue;
		}
		count++;
		if((count>=k && pre >=k) || count>=2*k) return true;
	}
	return false;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
