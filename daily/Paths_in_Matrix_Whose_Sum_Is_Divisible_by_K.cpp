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
	int k;

	int n = grid.size();
	int m = grid[0].size();
	long long mod = 1e9+7;
	long long dp[n][m][k];
	for(int i = 0;i< n;i++)
        for(int j = 0;j<m;j++)
            for(int l = 0;l<k;l++)
                dp[i][j][l] = 0;

	dp[0][0][grid[0][0]%k] = 1;
	for(int i = 0;i<n;i++){
		for(int j = 0; j<m;j++){
			if(i==0 && j ==0) continue;
			int remain = grid[i][j]%k;
			int up = i-1;
			int left = j -1;
			for(int l =0; l<k;l++){
				if(up>=0){
					dp[i][j][(l + remain)%k]+= dp[up][j][l];
					dp[i][j][(l+ remain)%k] %= mod;
				}
				if(left>=0){
					dp[i][j][(l+ remain)%k]+= dp[i][left][l];
					dp[i][j][(l + remain)%k]%=mod;
				}
			}
		}
	}
	cout<< dp[n-1][m-1][0]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
