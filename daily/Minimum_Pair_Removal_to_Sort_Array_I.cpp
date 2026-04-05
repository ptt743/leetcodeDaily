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
	int count = 0;
	while(1){
		bool isSort = true;
		int mindis = INT_MAX;
		int n = nums.size();
		for(int i = 1;i< n;i++){
			mindis = min(nums[i] + nums[i-1], mindis);
			if(nums[i]< nums[i-1]) isSort= false;
		}
		if(isSort) break;
		count++;
		vector<int> temp;
		bool check = false;
		for(int i = 0;i< n;i++){
			if(i<n-1 && (nums[i+1]+ nums[i])==mindis && !check){
				temp.push_back(mindis);
				check = true;
				i+=1;
                continue;
			}
            temp.push_back(nums[i]);
		}
		nums = temp;
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
