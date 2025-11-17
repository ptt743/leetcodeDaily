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
	vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
	int n = triangle.size();

	for(int i = 1;i< n;i++){
		for(int j = 0;j< triangle[i].size();j++){
			int val = triangle[i][j];
			int a = INT_MAX;
			int b = INT_MAX;
			if(j-1>=0){
				a = val + triangle[i-1][j-1];
			}
			if(j < triangle[i-1].size())
				b = triangle[i-1][j] + val;
			triangle[i][j] = min(a,b);
		}
	}
	int res = INT_MAX;
	for(int i =0;i< triangle[n-1].size();i++) res = min( res, triangle[n-1][i]);
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
