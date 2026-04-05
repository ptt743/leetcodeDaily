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
	int m; int n; int maxMove; int startRow; int startColumn;
	vector<vector<int>> predp(m,vector<int>(n,0));
	predp[startRow][startColumn]=1;
	vector<int> dx ={1,-1,0,0};
	vector<int> dy = {0,0,1,-1};
	int count = 0;
    	int mod = 1e9 + 7;
	for(int t =1;t<=maxMove;t++){
		vector<vector<int>> dp(m,vector<int>(n,0));
		for(int i = 0;i< m;i++){
			for(int j = 0;j< n;j++){
				for(int k = 0;k<4;k++){
					int ni = i + dx[k];
					int nj = j + dy[k];
					if(ni>=0 && ni<m && nj>=0 && nj<n){
						dp[ni][nj]+=predp[i][j];
                        dp[ni][nj]%=mod;
					}else {
                        count+= predp[i][j];
                        count%=mod;
                    }
				}
			}
		}
		predp = dp;
	}
	return count;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
