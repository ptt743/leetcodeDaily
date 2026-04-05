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
	int n;
	vector<vector<int>> queries;
	int m = queries.size();
	vector<vector<int>> count( n, vector<int> (n,0));
	for(vector<int> item : queries){
		int a,b,c,d;
		int row1= item[0], col1 = item[1], row2 = item[2], col2 = item[3];
		count[row1][col1]+= 1;
		row2++;
		col2++;
	       	if(col2<n){
			count[row1][col2]+=-1;
		}	
		if(row2<n){
			count[row2][col1]+= -1;
			if(col2<n){
	       			count[row2][col2]+= 1;
			}
		}
	}
	int res = 0;
	vector<vector<int>> result(n,vector<int>(n,0));
	vector<int> dp(n,0);
	for(int i =0;i< n;i++){
		int res = 0;
		for(int j = 0; j< n;j++){
			dp[j]+=count[i][j];
			res+= dp[j];
			result[i][j] = res;
		}
	}
	return result;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
