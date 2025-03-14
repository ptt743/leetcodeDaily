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
	vector<int> nums={1,1,1,1,1};
	int k = 0;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	deque<int> qq;
	int result = 0;
	for(int i =0;i< n;){
		qq.push_back(nums[i]);
		int next = i+1;
		while(next<n && nums[next]== nums[i]) {qq.push_back(nums[next]); next++;}
		i = next;

		bool check = false;
		while(qq.size()>1 && qq.back() - qq.front()>=k){
			if(qq.back() - qq.front() ==k) check = true;
			qq.pop_front();
		}
		if(check) result++;
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
