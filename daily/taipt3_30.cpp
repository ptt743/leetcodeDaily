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
	vector<int> nums = {1,1,1};
	long long k=5;
	int n =  nums.size();
	int left = 0;
	vector<long long> pre(n+1,0);
	for(int i =1;i<=n;i++) pre[i] = pre[i-1]+ nums[i-1];
	long long result = 0;
	for(int right = 1;right <=n;right++){
		long long curr = (pre[right] - pre[left])* (right - left);
		while( left<right && curr>=k){
			left++;
			curr = (pre[right] - pre[left]) * (right - left);
		}
		result += right - left;
		cout<< result <<endl;
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
