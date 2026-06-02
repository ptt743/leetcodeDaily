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

	function<void(int ,int)> heapify=[&]( int n, int i){
		int largest = i;
		int left = 2*i+1;
		int right = 2*i+2;

		if(left< n && nums[left] > nums[largest]){
			largest = left;
		}
		if(right < n && nums[right] > nums[largest]){
			largest = right;
		}
		if(largest !=i){
			swap(nums[i], nums[largest]);
			heapify(n,largest);
		}
	};

	for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
	for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
