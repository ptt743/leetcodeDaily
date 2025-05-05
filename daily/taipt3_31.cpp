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
	vector<int> nums= {1,4,2,1};
	int k = 3;
	int n = nums.size();
	unordered_map<int,int> pre;
	int maxVal = 0;
	for(int i =0;i<n;i++) maxVal = max(maxVal, nums[i]);
	int count = 0;
	long long result = 0;
	for(int right =0; right < n; right++){
		if(nums[right] == maxVal){
			pre[count] = right + 1;
			count++;
		}
		if(count>=k){
			int target = count - k;
			result+= pre[target];
		}
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
