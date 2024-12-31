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
<<<<<<< HEAD
	vector<int> nums={-1,3,2,0};
	int n = nums.size();
	// i < j  < k
	// nums[i] < nums[k] < nums[j]
	//
	int minval = 1e9;
	vector<int> mins(n,0);
	for(int i =0;i< n;i++){
		minval = min(minval, nums[i]);
		mins[i] = minval;
	}
	set<int> st;
	for(int i =n -1;i>=0;i--){
		auto it = st.lower_bound(nums[i]);
		if(it==st.begin()){
			st.insert(nums[i]);
			continue;
		}
		it--;
		cout<<*it <<" "<<mins[i]<<endl;
		if(*it > mins[i]){
			cout<<"YES"<<endl;
			return;
		}
		st.insert(nums[i]);
	}
	cout<<"NO"<<endl;
=======
			
>>>>>>> refs/remotes/origin/main
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
