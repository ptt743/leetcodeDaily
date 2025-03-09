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
struct option{
	bool operator()(int a, int b ){
		return  b<a;
	}
};
void solve(){
	priority_queue<int, vector<int>, option> pq;
	vector<int> nums = {3,2,3,1,2,4,5,5,6};
	int k  = 4;
	int n = nums.size();
	for(int i =0;i< n;i++){
		pq.push(nums[i]);
		if(pq.size()>k) pq.pop();
	}
	cout<< pq.top()<<endl;
}
void solve2(){
	vector<int> nums = {3,2,3,1,2,4,5,5,6};
	int k = 4;
	int n = nums.size();
	int max_value = -1e4, min_value = 1e4;
	for(int i = 0;i< n;i++){
		min_value = min(min_value, nums[i]);
		max_value = max(max_value, nums[i]);
	}
	vector<int> count(max_value - min_value + 1,0);
	for(int i =0 ; i<n;i++) count[nums[i] - min_value]++;
		
	for(int i = max_value - min_value ; i>=0;i--){
		k -= count[i];
		if(k<=0){
			cout<< min_value + i<<endl;
			return;
		}
	}
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
