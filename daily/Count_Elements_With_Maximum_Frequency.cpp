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

	vector<int> count(101,0);
	int maxVal = 0;
	for(int i =0;i< n;i++){
		count[nums[i]]++;
		maxVal = max(maxVal, count[nums[i]]);
	}
	int sum = 0;
	for(int i =1;i<=100;i++){
		if(count[i]==maxVal) sum+=maxVal;
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
