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
	vector<int> nums={-1,0};
	int target=-1;
	int n = nums.size();
	int left = 0, right = n-1;
	while(nums[left] + nums[right]!= target){
		if(nums[left] + nums[right]>target){
			right--;
		} else {
			left++;
		}
	}
	cout<<left+1<<" "<< right+1<<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
