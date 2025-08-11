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
	vector<int> nums={1,5,9,2,8};
	int k=2;
	int n = nums.size();

	vector<vector<int>> dp(n, vector<int>(k,1));
	for(int i =0;i< k;i++) dp[0][i] = 1;
	int result =2;
	for(int i =1;i<n;i++){
		for(int j =0 ;j<i;j++){
			int add = (nums[i] + nums[j])%k;
			dp[i][add]=  dp[j][add]+1;
			result = max(result,dp[i][add]);
		}
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
