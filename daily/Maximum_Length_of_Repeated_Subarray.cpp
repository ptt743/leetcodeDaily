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
	vector<int> nums1;
	vector<int> nums2;
	int n1 = nums1.size();
	int n2 = nums2.size();

    	int len = 0;
	vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
	for(int i = 1;i<=n1;i++){
		for(int j = 1;j<=n2;j++){
			if(nums1[i-1] == nums2[j-1]){
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                len = max(len, dp[i][j]);
            }
		}
	}
	return len;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
