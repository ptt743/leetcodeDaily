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
	vector<int> nums = {1,2,3,4,5};
	int n = nums.size();

	for(int i = 0;i< n-1;i++){
		for(int j = 0;j< n-1;j++){
			nums[j] = (nums[j] + nums[j+1])%10;
			cout<< nums[j]<<" ";
		}
		cout<<endl;
	}
	cout<< nums[0]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
