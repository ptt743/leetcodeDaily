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
	vector<vector<int>> grid;
	int n = grid.size();
	int m = grid.size();

	vector<vector<int>> rowsum(n, vector<int>(m+1,0));
	for(int i =0;i<n;i++){
		rowsum[i][0] = grid[i][0];
		for(int j = 1;j<=m;j++){
			if(i<m)rowsum[i][j] = rowsum[i][j-1] + grid[i][j]; 
			else rowsum[i][j] = rowsum[i][j-1];
		}	
	}

	vector<vector<int>> colsum(m, vector<int>(n,0));

	for(int i = 0;i<m;j++){
		colsum[i][0] = grid[0][i];
		for(int j = 1;j<=n;j++){
			if(i<n)colsum[i][j] = colsum[i][j-1] + grid[j][i];
			else colsum[i][j] = colsum[i][j-1];
		}
	}
	int ans = 1;
	for(int len = 1;len<=min(m,n);len++){
		for(int i =0;i<=n - len;i++){
			for(int j = 0;j<=n - len;j++){
				int equal = rowsum[i][j+len] - rowsum[i][j];
				for(int k = i+1; k< i+len;k++){
					
				}
				for(int k = j;k< j+len; k++){
					
				}
			}
		}
	} 
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
