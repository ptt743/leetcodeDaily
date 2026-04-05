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
	int k;
	int n = mat.size();
	int m = mat[0].size();

	for(int i =0;i<n;i++){
		vector<int> temp = mat[i];
		int step = k%m;
		for(int j = 0;j< step;j++){
			int pre = mat[i][m-1];
			for(int k = 0;k<m;k++){
                int t = mat[i][k];
				mat[i][k] = pre;
                pre = t;

			}
		}
		if(mat[i]!=temp) return false;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
