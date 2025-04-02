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
	vector<int> nums= {1,2,3};
	int n = nums.size();
	vector<long long> maxproduct(n,0);
	maxproduct[0] = -1e6;
	long long maxpre = nums[0];
	for(int i = 1;i<n-1;i++){
		long long product = maxpre - nums[i];
		maxproduct[i] = max(product, maxproduct[i-1]);
		maxpre = max(maxpre, (long long)nums[i]);
	}
	long long result = -1e12;
	for(int i =2;i< n;i++){
		result = max(result, maxproduct[i-1]*nums[i]);
	}
	cout<< ((result<0)?0:result) << endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
