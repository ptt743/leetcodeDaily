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
	int sum = 0;
	for(int i = 0;i<n;i++){
		int count = 0;
		int val = sqrt(nums[i]);
		int temp = nums[i]+1;
		if(nums[i]== val*val) continue;
		for(int j = 2;j< val;j++){
			if(nums[i]%val==0){
				count+=2;
				temp += j + (nums[i])/j;
			}
		}
		if(count==2) sum+= temp;
	}
	return sum;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
