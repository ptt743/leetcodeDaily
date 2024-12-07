#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<int> nums={2,3,0,1,4};
	int n = nums.size();
	vector<int> dp(n, 1e9);
	dp[0] = 0;
	for(int i =0;i< n;i++){
		for(int j =  1;j<= nums[i];j++){
			if(i+ j<n){
				dp[i+j]= min(dp[i+j], dp[i] + 1);
			}
		}
	}
	cout<< dp[n-1]<<endl;

}

void solve2(){
	vector<int> nums = {2,3,0,1,4};
	int n = nums.size();
	int current = 0;
	int maxjump = 0;
	int count =0;
	for(int i =0;i< n;i++){
		maxjump = max(maxjump, i + nums[i]);
		maxjump = min(maxjump,n-1);
		if(i==current){
			count++;
			current = maxjump;
		}
	}
	cout<< count-1<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
