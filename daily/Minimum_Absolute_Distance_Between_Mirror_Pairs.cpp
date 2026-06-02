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
	vector<int>& nums;
	int n = nums.size();
	unordered_map<int, int> mp;
	int dis = INT_MAX;
	function<int(int)> rever=[](int a){
		int result = 0;
		while(a>0){
			int item = a%10;
			a/=10;
			result = result*10 + item;
		}
		return result;
	};
	for(int i = 0;i< n;i++){
        //while(nums[i]%10==0) nums[i]/=10;
		int reverNum = rever(nums[i]);
		if(mp.find(nums[i])!=mp.end() && mp[nums[i]]<i){
			dis = min(dis,i - mp[nums[i]]);
		}
        mp[reverNum] = i;

	}
	return (dis==INT_MAX)?-1:dis;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
