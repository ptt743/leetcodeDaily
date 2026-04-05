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
	int sum = 0;

	for(int item : nums) sum += item;
	if(sum%4!=0) return false;
	int edge = sum/4;
	
	function<bool(int, int,int,int,int)> RC=[&](int index, int one, int two,int three, int four){
		if(index==n && one == two && two == three && three == four) return true;
		if(index>=n) return false;
		bool check = false;
		if(one + nums[index]<=edge)
			check |= RC(index+1, one + nums[index], two, three, four);
		if(two + nums[index]<=edge)
			check |= RC(index+1, one, two + nums[index], three, four);
		if(three + nums[index]<=edge)
			check |= RC(index+1, one , two, three + nums[index], four);
		if(four + nums[index]<=edge)
			check |= RC(index+1, one , two, three, four + nums[index]);
		return check;
	};
	return RC(0,0,0,0,0);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
