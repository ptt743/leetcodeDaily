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
	vector<vector<char>> boxGrid;
	int n = boxGrid.size();
	int m = boxGrid[0].size();
	for(int i = 0;i< n;i++){
		int right = m-1;
		for(int j = m-1; j>=0;j--){
			if(boxGrid[i][j]=='*'){
				right = j-1;
			}
			if(boxGrid[i][j]=='#'){
				swap(boxGrid[i][j], boxGrid[i][right]);
				right--;
			}
		}
	}
	vector<vector<int>> res( m, vector<int>(n,0));
	for(int i =0;i< n;i++){
		for(int j = 0;j< m;j++){
			res[j][n-1-i] = boxGrid[i][j];
		}
	}
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
