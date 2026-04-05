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
	int k;
	int dist;
	int n = nums.size();
	multiset<long long> maxHeap;
	multiset<long long> minHeap;
	long long res = LLONG_MAX;
	int left =1;
    	k-=1;
	long long currSum = nums[0];
	for(int i = 1;i<n;i++){
		if(i - left> dist){
			auto it = minHeap.find(nums[left]);
			if(it!=minHeap.end()){
				minHeap.erase(it);
			} else {
				auto it2 = maxHeap.find(nums[left]);
				maxHeap.erase(it2);
				currSum -= nums[left];
			}
			left++;
		}
		maxHeap.insert(nums[i]);
        currSum+=nums[i];
		if(maxHeap.size()>k){
            currSum-= *maxHeap.rbegin();
			minHeap.insert(*maxHeap.rbegin());
			maxHeap.erase(prev(maxHeap.end()));
		}else if(minHeap.size()>0) {
			if(*maxHeap.rbegin() > *minHeap.begin()){
				currSum += *minHeap.begin() - *maxHeap.rbegin();
				int temp = *maxHeap.rbegin();
				maxHeap.erase(prev(maxHeap.end()));
				maxHeap.insert(*minHeap.begin());
				minHeap.erase(minHeap.begin());
				minHeap.insert(temp);
			}
		}
		if(i>=k)res= min(res, currSum);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
