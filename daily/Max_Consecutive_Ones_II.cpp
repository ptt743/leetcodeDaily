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
	int n= nums.size();
	vector<int> prefix(n,0);
	vector<int> suffix(n,0);
	int countp=0;
	for(int i =0;i<n;i++){
		prefix[i] = count;
		countp = (nums[i]==1)?countp+1:0;
	}
	int counts = 0;
	for(int i = n-1;i>=0;i--){
		suffix[i] = counts;
		counts = (nums[i]==1)counts+1:0; 
	}
	int maxVal = 0;
	for(int i =0;i<n;i++){
		maxVal = max(maxVal, prefix[i] + suffix[i]+1);
	}
	return maxVal;
}

void solve2(){
	vector<int> nums;
	int n = nums.size();
	int lS = 0;
	int left = 0, right =0;
	int numsZ = 0;

	while(right<n){
		if(nums[right]==0){
			numsZ++;
		}
		while(numsZ==2){
			if(nums[left]==0)numsZ--;
            left++;
		}
		lS = max(lS, right - left+1);
        right++;
	}
	return lS;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
