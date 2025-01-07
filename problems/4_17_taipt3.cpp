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
	vector<int> nums={4,2,2,2,4,4,2,2};
	int limit = 0;
	int n = nums.size();
	multiset<int> st;
	int left = 0;
	int res = 0;
	for(int i =0;i< n;i++){
		st.insert(nums[i]);
		while(left<=i && *st.rbegin() - *st.begin()> limit){
			st.erase(st.find(nums[left]));
			left++;
		}
		res = max(res, i - left + 1);
	}

	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
