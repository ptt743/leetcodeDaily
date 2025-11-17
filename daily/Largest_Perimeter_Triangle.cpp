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
	int n = nums.size();

	sort(nums.begin(), nums.end());

	function<bool(int,int,int)> check=[&](int a, int b, int c){
		return (a < b +c) && (b < c+a) && ( c < b+ a);
	};
	int res =0;
	for(int i = n-1;i>=2;i--){
		if(check(nums[i], nums[i-1], nums[i-2])){
			res = nums[i] + nums[i-1] + nums[i-2];
			break;
		}
	}
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
