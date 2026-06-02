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
	vector<int> nums1;
	vector<int> nums2;
	unordered_set<int> st;
	for(int item : nums1) st.insert(item);
	int res = INT_MAX;
	for(int item : nums2)
		if(st.find(item)!=st.end()) res = min( res, item);
	return ( res ==INT_MAX)?-1:res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
