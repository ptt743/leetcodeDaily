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
	vector<vector<int>> mat;
	int threshold;

	int n = mat.size();
	int m = mat[0].size();
	vector<vector<int>> prefix(n+1, vector<int>(m+1,0));

	for(int i =1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			prefix[i][j] = mat[i-1][j-1] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
		}
	}

	int l = 0, r = min(m,n);
	while(l<=r){
		int mid = (l + r)/2;
		bool check = false;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=m;j++){
				if(i-mid>=0 && j-mid>=0){
					int val = prefix[i][j] - prefix[i-mid][j] - prefix[i][j-mid] + prefix[i-mid][j-mid];
					if(val<= threshold){
						check = true;
					}
				}
			}
		}
		if(check) l = mid+1;
		else r = mid-1;
	}
	return r;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
