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
	vector<vector<char>> grid;
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> suffixbot(n);
	vector<int> temp1(m,0);
	for(int i =n-1;i>=0;i--){
		for(int j = 0;j< m;j++){
			if(grid[i][j]=='W') temp1[j] = 0;
			else if(grid[i][j]=='E') temp1[j]++;
		}
		suffixbot[i]=temp1;
	}

	vector<vector<int>> suffixright(m);
	vector<int> temp2(n,0);
	for(int i = m-1;i>=0;i--){
		for(int j = 0;j<n;j++){
			if(grid[j][i]=='W') temp2[j] = 0;
			else if(grid[j][i]=='E') temp2[j]++;
		}
		suffixright[i] = temp2;
	}
	int ans =0;
	vector<int> temp3(m,0);
	for(int i = 0;i<n;i++){
		int count = 0;
		for(int j = 0;j<m;j++){
			if(grid[i][j]=='0')ans = max( ans, count + temp[j] + suffixbot[i][j] + suffixright[j][i]);
			if(grid[i][j]=='W') temp[j]=0, count=0;
			else if(grid[i][j]=='E') temp[j]++, count++;
		}
	}
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
