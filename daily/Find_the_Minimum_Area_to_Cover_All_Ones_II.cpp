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
#include <climits>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<vector<int>> grid = {{1,0,1},{1,1,1}};
	function<vector<vector<int>>(vector<vector<int>>&)> rotate=[&](vector<vector<int>>& input){
		int n = input.size();
		int m = input[0].size();
		vector<vector<int>> result = vector<vector<int>>(m, vector<int>(n,0));
		for(int i = 0;i<n;i++){
			for(int j = 0;j < m;j++){
				result[m - j-1][i] = input[i][j];
			}
		}
		return result;
	};

	function<int(vector<vector<int>>&, int, int, int, int)> cal= [&](vector<vector<int>>& input, int left, int right, int up, int down){
		int min_j = input[0].size(), max_i = 0;
		int min_i = input.size() , max_j = 0;
		for(int i =  up; i< down; i++){
			for(int j = left ; j < right; j++){
				if(input[i][j] == 1 ){
					min_i = min(min_i, i);
					max_i = max(max_i, i);
					min_j = min(min_j, j);
					max_j = max(max_j, j);
				}
			}
		}
		int res =  (min_i<=max_i)?(( max_i - min_i +1) * ( max_j - min_j+1)):(INT_MAX/3);
		return res;
	};

	function<int(vector<vector<int>>&)> sol=[&](vector<vector<int>>& input){
		int res  = input.size() * input[0].size();
		int n = input.size();
		int m = input[0].size();
		for(int i = 1;i< n;i++){
			for(int j = 1; j<m;j++){
				res = min(res,cal(input, 0, j, 0, i) + cal(input, j, m, 0, i) + cal(input, 0, m, i, n));
				res = min(res,cal(input, 0, m, 0, i) + cal(input, 0, j, i, n) + cal(input, j, m, i, n));
			}
		}
		for(int i = 1;i<n-1;i++){
			for( int j = i+1;j< n;j++){
				res = min(res,cal(input, 0,m, 0,i) + cal(input, 0,m,i,j) + cal(input, 0,m,j,n));
			}
		}
		return res;
	};

	vector<vector<int>> rotateGrid = rotate(grid);

	int result = min(sol(grid),sol(rotateGrid));
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
