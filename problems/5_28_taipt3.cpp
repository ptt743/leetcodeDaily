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
	sort(nums.begin(), nums.end());
	long long res = 0;
	int left = 0;
	for(int i =0;i< n;i++){
		while(nums[left] + 
			int count = i;
			res += (long long)(count) * (count-1)/2;
	}
	cout<< res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
