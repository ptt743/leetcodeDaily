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
#include <climits>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<vector<int>> mat={{1,0,1},{1,1,0},{1,1,0}};

	int n = mat.size();
	int m = mat[0].size();

	vector<int> curr(m,0);
	int res = 0;
	for(int i =0;i<n;i++){
		for(int j  =0; j <m;j++){
			if(mat[i][j]==0) curr[j] = 0;
			else curr[j]++;
			
			int currIndex =j;
			int minVal = INT_MAX;
			while(currIndex >=0 && curr[currIndex]!=0){
				minVal = min(minVal, curr[currIndex]);
				res +=minVal;
				currIndex--;
			}
		}
	}
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
