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
	vector<vector<int>> intervals;
	int n = intervals.size();
	function<bool(vector<int>&, vector<int>&)> option=[&](vector<int>& a, vector<int>&b){
		return a[1] < b[1];
	};
	sort(intervals.begin(), intervals.end(), option);
	int temp = intervals[0][1];
	int count=0;
	for(int i=1;i<n;i++){
		if(intervals[i][0] >= temp){
			temp = intervals[i][1];
		} else count++;
	}
	return count;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
