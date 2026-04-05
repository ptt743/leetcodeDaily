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
	string segment = "";
	for(int i =0;i< n;i++){
		if(i>0) segment+='/';
		segment+= toString(nums[i]);
	}
	
	function<vector<float>(string)> RC=[&](string s){
		vector<float> res;
		for(int i = left+1; i < right;i++){
			vector<float> left = RC(left, i);
			vector<float> right = RC(i+1, right);
			for(float item1 : left){
				for(float item2: right){
					res.push_back(item1/item2);
				} 
			}
		}
		if(res.empty()) res.push_back(nums[left]);
		return res;
	}
	vector<int> result = RC(0,n-1);
	

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
