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
	vector<int> nums={3,4,5,6,7,8};
	int n = nums.size();
	int res = 0;
	function<void(int, int )> rc=[&](int xr, int index){
		if(index==n){
			res+=xr;
			return;
		}
		rc(xr^nums[index], index+1);
		rc(xr, index+1);
	};
	rc(0,0);
	cout<< res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
