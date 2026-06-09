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
	int = nums.size();

	vector<int> left(n,0), right(n,0);
	for(int i =1;i< n; i++){
		left[i] = left[i-1] + nums[i-1];
	}
	for(int i =n-2;i>=0; i--){
		right[i] = right[i+1] + nums[i+1];
	}
	vector<int> result(n,0);
	for(int i = 0;i< n;i++) result[i] = abs(left[i] - right[i]);
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
