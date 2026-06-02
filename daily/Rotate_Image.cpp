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
	vector<vector<int>> matrix;
	int n= matrix.size();
	int m = matrix[0].size();
	for(int i=0;i< n;i++){
		for(int j = i ;j< n;j++){
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	for(int i = 0;i<n;i++){
		reverse(matrix[i].begin(), matrix[i].end());
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
