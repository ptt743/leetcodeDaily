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
	vector<int> aliceValues;
	vector<int> bobValues;

	int n = aliceValues.size();
	vector<pair<int,int>> arr;
	for(int i = 0;i< n;i++) arr.push_back({aliceValues[i] + bobValues[i],i});
	sort(arr.begin(), arr.end(),[](pair<int,int> a, pair<int,int> b){ return a.first> b.first;});
	int first =0, second = 0;
	for(int i = 0;i< n;i++){
		if(i%2==0) first+=aliceValues[arr[i].second];
		else second += bobValues[arr[i].second];
	}
	if(first > second) return 1;
	else if( first < second ) return -1;
	return 0;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
