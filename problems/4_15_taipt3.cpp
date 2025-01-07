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
	vector<int> nums={-3,-2,-3};
	int n = nums.size();
	vector<int> suffix(n+1,-1e9);
	suffix[n] = 0;
	for(int i = n-1;i>=0;i--){
		suffix[i] = suffix[i+1] + nums[i];	
	}
	vector<int> maxsuf(n+1, -1e9);
	for(int i =n-1;i>=0;i--){
		maxsuf[i] = max(suffix[i+1], maxsuf[i+1]);
	}
	int maxcurr= 0;
	int maxres = -1e9;

	int prefixsum =0;
	int specialmax = -1e9;
	for(int i = 0;i< n;i++){
		maxcurr = max( maxcurr + nums[i], nums[i]);
		maxres = max(maxres, maxcurr);

		prefixsum = prefixsum + nums[i];
		specialmax = max(specialmax, prefixsum + maxsuf[i]);
	}
	cout<<max( maxres, specialmax)<<endl;
}

void solve2(){
	vector<int> nums = {-3,-2,-3};
	int n = nums.size();
	int sum = 0;
	int maxcurr = 0;
	int maxres = -1e9;

	int mincurr = 0;
	int minres = 1e9;
	for(int i =0;i< n;i++){
		maxcurr  = max(maxcurr + nums[i], nums[i]);
		maxres = max(maxres, maxcurr);
		mincurr = min(mincurr + nums[i], nums[i]);
		minres = min(minres, mincurr);
		cout<< maxres <<" "<<minres<<endl;
		sum += nums[i];
	}
	if(minres == sum) return maxres;
	return max( maxres, sum - minres);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
