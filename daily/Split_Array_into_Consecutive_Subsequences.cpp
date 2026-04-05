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
	
	unordered_map<int,int> left;
	unordered_map<int,int> ending;

	for(int item : nums) left[item]++;

	for(int item : nums){
		if(left[item]==0) continue;

		if(ending[item-1]>0){
			left[item]--;
			ending[item]++;
			ending[item-1]--;
			continue;
		}
		if(left[item+1]>0 && left[item+2]>0){
			left[item]--;
			left[item+1]--;
			left[item+2]--;
			ending[item+2]++;
			continue;
		}
		return false;
	}
	return true;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
