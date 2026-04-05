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

	int n = matrix.size();
	int m= matrix[0].size();
	vector<int> temp(m,0);
	int res = 0;
	for(int i =0;i< n;i++){
		for(int j = 0; j< m;j++){
			if(matrix[i][j]==1) temp[j]+=1;
			else temp[j] = 0;
		}
		vector<int> arr = temp;
		sort(arr.begin(), arr.end());
		for(int j = m-1;j>=0;j--){
			res = max(res, arr[j]*(m- j));	
		}
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
