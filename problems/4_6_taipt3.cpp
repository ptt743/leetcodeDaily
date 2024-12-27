#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<map>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<vector<int>> intervals= {{1,4},{2,3},{3,4}};
	int n = intervals.size();
	set<int> st;
	unordered_map<int,int> mp;
	for(int i =0;i<n;i++){
		st.insert(intervals[i][0]);
		mp[intervals[i][0]] = i;
	}
	for(int i =0;i< n;i++){
		int value = intervals[i][1];
		auto it = st.lower_bound(value);
		if(it!=st.end()){
			cout<< mp[*it]<<endl;
		} else cout<<"-1"<<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
