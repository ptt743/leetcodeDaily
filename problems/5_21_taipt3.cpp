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
	int target;
	int n = matrix.size();
	int m = matrix[0].size();
	int left =0, right = n * m-1;
	while(left <= right){
		 int mid = (left + right)/2;
	         int x = mid/m;
		 int y= mid%m;
		 if(matrix[x][y]==target) return true;
		 if(matrix[x][y] < target) left = mid+1;
		 else right = mid-1;
	}
	return false;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
