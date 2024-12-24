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
	vector<int> nums={7,7,7,7,7,7,7};
	int n = nums.size();
	vector<int> ans;
	for(int i =0;i< n;i++){
		if(ans.size()==0 || ans.back()< nums[i]){
			ans.push_back(nums[i]);
		} else {
			int left = 0, right = ans.size()-1;
			while(left<=right){
				int mid = (left + right)/2;
				if(ans[mid] < nums[i]) left = mid +1;
				else right = mid -1;
			}
			if(left< ans.size() && ans[left]> nums[i]) ans[left] = nums[i];
		}
	}
	cout<< ans.size()<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
