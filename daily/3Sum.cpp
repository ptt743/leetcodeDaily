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
	sort(nums.begin(), nums.end());
	int pre = -1e5-1;
    	int n = nums.size();
	vector<vector<int>> res;
	for(int i = 0;i< n;i++){
        
		if(nums[i] == pre) continue;
        unordered_set<int> st;
        int prej = -1e5-1;
		for(int j = i+1;j< n;j++){
            if(nums[j]==prej) continue;
			if(st.find(nums[j])!= st.end()){
				res.push_back({nums[i],(-1) *nums[i] +  (-1)*nums[j] ,nums[j]});
                prej = nums[j];
			}
			st.insert((-1)*nums[i] + (-1)* nums[j]);
		}
		pre = nums[i];
		
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
