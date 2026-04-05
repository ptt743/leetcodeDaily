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
	int len = 0;
	for(int i = 0;i< n;i++){
		unordered_set<int> stodd;
		unordered_set<int> steven;
		for(int j = i ; j< n;j++){
			if(nums[j]%2==0){
				steven.insert(nums[j]);
			} else {
				stodd.insert(nums[j]);
			}
			if(stodd.size() == steven.size()){
				len = max(len, j - i+1);		
			}
		}
	}
	return len;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
