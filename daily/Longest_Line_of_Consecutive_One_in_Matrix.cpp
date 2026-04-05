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
	vector<vector<int>> mat;
	int n = mat.size();
	int m = mat[0].size();
	int res = 0;
	vector<int> dp1(m,0);
	for(int i = 0;i< n;i++){
		for(int j =0;j< m;j++){
			if(mat[i][j]==0) dp1[j] =0;
			else dp1[j]++;
			res = max(res, dp1[j]);
		}
	}
	vector<int> dp2(n,0);
	for(int i = 0;i< m;i++){
		for(int j =0;j< n;j++){
			if(mat[j][i]==0) dp2[j] =0;
			else dp2[j]++;
			res = max(res, dp2[j]);
		}
	}
	vector<vector<int>> dp3(n, vector<int>(m,0));
	for(int i = 0;i< n;i++){
		for(int j = 0;j<m;j++){
			if(mat[i][j]==0) dp3[i][j]=0;
			else{
				int prei = i-1;
				int prej = j-1;
				dp3[i][j] =1;
				if(prei >=0 && prej>=0) dp3[i][j]+= dp3[prei][prej];
			}
			res = max(res, dp3[i][j]);
		}
	}
	vector<vector<int>> dp4(n, vector<int>(m,0));
	for(int i = 0;i< n;i++){
		for(int j = m-1;j>=0;j--){
			if(mat[i][j]==0) dp4[i][j]=0;
			else{
				int prei = i-1;
				int prej = j+1;
				dp4[i][j] =1;
				if(prei >=0 && prej<m) dp4[i][j]+= dp4[prei][prej];
			}
			res = max(res, dp4[i][j]);
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
