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
struct node{
	int result;
	int value;
	int index;
};
struct option{
	bool operator()(node a, node b){
		return a.result > b.result;
	}
};
void solve(){
	vector<int> nums1 = {1,2,4,5,6};
	vector<int> nums2 = {3,5,7,9};
	int k = 20;

	priority_queue<node, vector<node>, option>pq1, pq2;
	int count1=nums2.size();
	for(int nums: nums1){
		int count = (count1>0)?count1:0;
        if(count==0)continue;
		pq1.push({nums+nums2[nums2.size() - count],nums, count });
		count1--;
	} 
	int count2 = nums1.size()-1;
	for(int nums: nums2){
		int count = (count2>0)?count2:0;
        if(count==0)continue;
		pq2.push({nums + nums1[nums1.size()- count],nums, count});
		count2--;
	}
	vector<vector<int>> res;
	while(k--){
		node top1 ={(int)1e9,0,0};
		if(!pq1.empty()){
			top1 = pq1.top(); 
			pq1.pop();
		}
		node top2 ={(int)1e9,0,0};
		if(!pq2.empty()){
			top2 = pq2.top(); 
			pq2.pop();
		}

		if(top1.result < top2.result){
			res.push_back({top1.value, nums2[nums2.size() - top1.index]});
			top1.index--;
		}else {
			res.push_back({nums1[nums1.size()- top2.index], top2.value});
			top2.index--;
		}
		if(top1.index>0) pq1.push({top1.value + nums2[nums2.size() - top1.index] ,top1.value, top1.index});
		if(top2.index>0) pq2.push({top2.value + nums1[nums1.size() - top2.index] ,top2.value, top2.index});
	}	
	for(vector<int> re: res) cout<<re[0]<<" "<<re[1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
