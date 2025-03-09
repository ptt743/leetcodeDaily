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
	vector<int> nums={5,4,2,4};
	int n = nums.size();
	map<int,int> mp;
	int left = 0;
	long long result =0;
	for(int i =0;i< n;i++){
		mp[nums[i]]++;
		while(!mp.empty() && (mp.rbegin()->first - mp.begin()->first >2)){
			mp[nums[left]]--;
			if(mp[nums[left]]==0){
				mp.erase(nums[left]);
			}
			left++;
		}
		result += (long long)(i - left + 1);
	}
	cout<< result <<endl;
}
void solve2(){
	vector<int> nums;
	int n = nums.size();
	priority_queue<int, vector<int>, function<bool(int,int)>> minHeap(
		[&nums](int a, int b) { return nums[a] > nums[b];}
	);
	priority_queue<int, vector<int>, function<bool(int,int)>> maxHeap(
		[&nums](int a, int b) { return nums[a] < nums[b];}		
	);

	int left = 0, right = 0;
	long long result = 0;
	for(;right< n;right++){
		maxHeap.push(right);
		minHeap.push(right);
		while(nums[maxHeap.top()] - nums[minHeap.top()]>2){
			while(!minHeap.empty() && minHeap.top() <= left) minHeap.pop();
			while(!maxHeap.empty() && maxHeap.top() <=left) maxHeap.pop();
			left++;
		}
		result += (long long)(right - left +1);
	}
	cout<< result;	
}

void solve3(){
	vector<int> nums={1,2,3};
	int n = nums.size();
	deque<int> mindq, maxdq;
	int left = 0, right =0;
	long long result = 0;
	for(;right< n;right++){
		while(!maxdq.empty() && nums[right] > nums[maxdq.back()]) maxdq.pop_back();
		maxdq.push_back(right);
		while(!mindq.empty() && nums[right] < nums[mindq.back()]) mindq.pop_back();
		mindq.push_back(right);
		while(nums[maxdq.front()] - nums[mindq.front()]>2){
			while(left >= mindq.front()) mindq.pop_front();
			while(left >= maxdq.front()) maxdq.pop_front();
			left++;
		}
		result += (long long)(right - left +1);
	}
	cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve3();
    return 0;
}
