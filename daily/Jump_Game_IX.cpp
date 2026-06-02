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
	struct component{
		int val;
            	int left;
		int right;
	};
	vector<component> st;

	for(int i=0 ;i< nums.size();i++){
		component item = {nums[i], i, i};
		while(!st.empty() && st.back().val > nums[i]){
		 	component temp = st.back();
			st.pop_back();
			item.val = max(item.val, temp.val);
			item.left = temp.left;

		}
		st.push_back(item);
	}
	vector<int> res (n,0);
	for(int i = 0;i< st.size();i++){
		for(int j = st[i].left; j<= st[i].right; j++) res[j] = st[i].val;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
