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
	]int n= nums.size();

	vector<vector<int>> record(101, vector<int>());
	for(int i = 0;i< n;i++){
		record[nums[i]].push_back(i);
	}
	int len = INT_MAX;
	for(int i =1;i<=100;i++){
		for(int j = 1;j<(int)record[i].size()-1;j++){
			int a = record[i][j-1];
			int b = record[i][j];
			int c = record[i][j+1];
			len = min(len, abs(a-b) + abs(a-c) + abs(b-c));
		}
	}
	return len==INT_MAX?-1:len;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
