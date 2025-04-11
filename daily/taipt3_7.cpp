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
	vector<int> nums={5,9,18,54,108,540,90,180,360,720};
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> dp = vector<vector<int>>(n,vector<int>());
	for(int i =0;i< n;i++){
		dp[i].push_back(nums[i]);
		for(int j = i-1;j>=0;j--){
			if(nums[i] % nums[j]==0  && (dp[j].size()+1) > dp[i].size()){
				cout<< "-----"<<nums[i]<<endl;
				vector<int> temp = dp[j];
				temp.push_back(nums[i]);
				dp[i]  = temp;
			}
		}
	}
	vector<int> result;
	for(int i =0;i< n;i++){
		if(dp[i].size() > result.size()) result = dp[i];
	}
	for(int i =0;i< result.size();i++) cout<< result[i]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
