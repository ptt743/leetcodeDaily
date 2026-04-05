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

	int sum = 0;
	for(int item : nums) sum+= item;

	int count = 0;
	int temp = 0;
	for(int i = 0;i< n-1;i++){
		temp += nums[i];
		if(abs(sum - temp - temp)%2==0) count++;
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
