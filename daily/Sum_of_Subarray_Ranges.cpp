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
	long long result = 0;

	stack<int> stmin;


	for(int i = 0;i< n;i++){
		while(!stmin.empty() && nums[stmin.top()] > nums[i]){
			int index = stmin.top();
			stmin.pop();
			int left = (stmin.empty())?0:(stmin.top()+1);
			result+= (-1ll)* nums[index] * (i - index) * (index - left+1);
		}
		stmin.push(i);
	}
	while(!stmin.empty()){
		int index = stmin.top();
		stmin.pop();
		int left = (stmin.empty())?0:(stmin.top()+1);
		result += (-1ll) * nums[index]* (n - index) * (index - left+1);
	}
	stack<int> stmax;
	for(int i = 0; i< n;i++){
		while(!stmax.empty() && nums[stmax.top()]< nums[i]){
			int index = stmax.top();
			stmax.pop();
			int left = (stmax.empty())?0:(stmax.top()+1);
			result += (1ll) * nums[index] *(i - index) * (index - left+1);
		}
		stmax.push(i);
	}
	while(!stmax.empty()){
		int index = stmax.top();
		stmax.pop();
		int left = (stmax.empty())?0:(stmax.top()+1);
		result+= (1ll)*nums[index]*(n - index) * (index - left+1);
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
