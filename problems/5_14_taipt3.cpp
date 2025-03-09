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
	vector<int> nums={1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,1,1,0,1};
	int n = nums.size();
	int result = 0;
	for(int i =0;i< n-2;i++){
		if(nums[i]==0){
			nums[i]^=1;
			nums[i+1]^=1;
			nums[i+2]^=1;
			result++;
		}
	}
	if(nums[n-1]==0 || nums[n-2]==0) return -1;
	
	return result;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
