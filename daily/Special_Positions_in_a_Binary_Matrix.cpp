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

	vector<int> countR(n,0);
	vector<int> countC(m,0);

	for(int i = 0;i< n;i++){
		for(int j = 0lj< m;j++){
			if(mat[i][j]==1){
				countR[i]++;
				countC[i]++;
			}
		}
	}
	int res = 0;
	for(int i = 0;i< n;i++){
		for(int j = 0;j< m;j++){
			if(mat[i][j]==1 && countR[i]==1 && countC[i]==1) res++;
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
