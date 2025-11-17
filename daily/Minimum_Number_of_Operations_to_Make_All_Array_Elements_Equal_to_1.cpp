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


int solve(){
	vector<int> nums={6,10,15};
	int n = nums.size();
	function<int(int,int)>gcd = [&](int a, int b){
		if(b==0) return a;
		return gcd(b, a%b);
	};
	
	int count = 0;
	int g = 0;
	for(int num: nums){
		if(num==1) count++;
		g = gcd(g, num);
	}

	if(count>0) return n - count;
	if(g>1) return -1;

	int min_len = n;
	for(int i =0;i< n;i++){
		int g = 0;
		for(int j = i ;j< n;j++){
			g= gcd(g, nums[j]);
			if(g==1){
				min_len= min(min_len, j-i+1);
			}
		}
	}

	return min_len + n - 2;//min_len -1 + n -1
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
