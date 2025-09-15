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

	function<vector<vector<int>> rotate=[&](){
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> result = vector<vector<int>>(m, vector<int>(n,0));
		for(int i = 0;i<n;i++){
			for(int j = 0;j < m;j++){
				result[j][i] = grid[i][j];
			}
		}
		return result;
	};

	function<int(vector<vector<int>>, int, int, int, int)> cal= [&](, vector<vector<int>>& input, int left, int right, int up, int down){
		int min_j = right, max_i = 0;
		int min_i = up, max_j = 0;
		for(int i =  up, i<=down; i++){
			for(int j = left , j < right; j++){
				if(input[i][j] == 1 ){
					min_i = min(min_i, i);
					max_i = max(max_i, i);
					min_j = min(min_j, j);
					max_j = max(max_j, j);
				}
			}
		}
		return ( max_i - min_i) * ( max_j - min_j );
	};

	function<int()> solve=[&](){
		for(int i = 1;i< n;i++){
			for(int j = 1; j< m;j++){
					
			}
		}

	}
	
	

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
