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
	vector<int> nums={5,7,11,12,12};
	map<int,int> mp;
	set<int> st;
	int n = nums.size();
	for(int i =0;i< n;i++){
		st.insert(nums[i]);
		mp[nums[i]]++;
	}
	int count = 0;
	if(st.size()==n){
		return count;
	}
	int left = -1;
	int check = n;
	while( left< n){
		bool flag = false;
		for(int i =0;i< 3;i++){
			if(left+1<n) left++;
			else continue;
			check--;
			mp[nums[left]]--;
			if(mp[nums[left]]==0) st.erase(nums[left]);
			if(check == st.size()){
				flag = true;
			}
		}
		count++;
		if(flag == true){
			return count;
		}

	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
