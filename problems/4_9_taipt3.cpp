#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<int> nums = {2,0,2};
	vector<vector<int>> queries={{0,2},{0,2},{1,1}};
	sort(queries.begin(), queries.end());
	int n = nums.size();
	int temp = 0;
	priority_queue<int, vector<int>, greater<int>> minheap;
	priority_queue<int> maxheap;
	int count = 0;
	for(int i =0;i< n;i++){
		while(temp<queries.size() && queries[temp][0] <=i){
			maxheap.push(queries[temp][1]);
			temp++;
		}
		nums[i] -= minheap.size();
		while(nums[i]>0 && !maxheap.empty() && maxheap.top() >= i) {
			minheap.push(maxheap.top());
			maxheap.pop();
			count++;
			nums[i]--;
		}
		if(nums[i]>0){
			cout<<"-1"<<endl;
			return;
		}
		while(!minheap.empty() && minheap.top()==i){
			minheap.pop();
		}
	}
	cout<< queries.size() - count<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
