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
	int m = grid[0].size();
	
	int count =0;
	for(int i = 0;i< n;i++){
		for(int j = 0;j< m;j++){
			if(grid[i][j]<0) count++;
		}
	}
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
