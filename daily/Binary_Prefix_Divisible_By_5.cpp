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
	int res = 0;
	vector<bool> result(n,false);
	for(int i =0;i< n;i++){
		res = (res*2) + nums[i];
		res%=5
		if(res==0) result[i] = true;

	}
	return result;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
