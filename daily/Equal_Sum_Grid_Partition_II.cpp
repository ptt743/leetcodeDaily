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

	long long total = 0;
	for(int i = 0;i< n;i++){
		for(int j = 0; j< m;j++){
			total += grid[i][j];
		}
	}
	function<vector<vector<int>>(vector<vector<int>> &)> rotate=[&]( vector<vector<int>> &arr){
		int n1 = arr.size();
		int m1 = arr[0].size();
		vector<vector<int>> temp(m1, vector<int>(n1,0));
		for(int i = 0;i< n1;i++){
			for(int j = 0;j<m1;j++){
				temp[j][i] = arr[i][j];
			}
		}
		for(int i=0; i<m1;i++) reverse( temp[i].begin(), temp[i].end());
		return temp;
	};

	for(int i =0;i< 4;i++){
		grid = rotate(grid);
		int sum = 0;
		n = grid.size();
		m = grid[0].size();
		if(n<2){
			continue;
		}
		if(m==1){
			for (int i = 0; i <n - 1; i++) {
                    		sum += grid[i][0];
                    		int tag = sum * 2 - total;
                    		if (tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                        		return true;
                    		}
			}
			continue;
		}
		unordered_set<long long> exist;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
			    exist.insert(grid[i][j]);
			    sum += grid[i][j];
			}
			int tag = sum * 2 - total;
			if (i == 0) {
			    if (tag == 0 || tag == grid[0][0] || tag == grid[0][m - 1]) {
				return true;
			    }
			    continue;
			}
			if (exist.contains(tag)) {
			    return true;
			}
		}
	}
	return false;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
