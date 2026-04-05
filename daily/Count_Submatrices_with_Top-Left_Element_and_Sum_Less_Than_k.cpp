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
	vector<vector<int>>& grid;
	int k;

	int n = grid.size();
	int m = grid[0].size();

	vector<int> col(m,0);
	int count = 0;
	for(int i =0;i< n;i++){
		int res =0;
		for(int j = 0;j< m;j++){
			col[j]+=grid[i][j];
			res+= col[j];
			if(res<=k) count++;
		}
	}
	return count;
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
