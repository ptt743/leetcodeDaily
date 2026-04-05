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
	int n;
	vector<vector<int>> mines;
	int m = mines.size();

	vector<vector<int>> ma( n, vector<int>(n, 1));
	for(int i = 0;i < m;i++){
		ma[mines[i][0]][mines[i][1]] = 0;
	}
	vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));
	vector<vector<int>> prefixv(n+1, vector<int>(n+1,0));


	for(int i = 1; i <=n;i++){
		for(int j = 1;j<=n;j++){
			prefixv[i][j] = prefixv[i-1][j] + ma[i-1][j-1];
		}
	}
	for(int i =1;i<=n;i++){
		for(int j =1; j<=n;j++){
			prefix[j][i] = prefix[j][i-1] + ma[j-1][i-1];
		}
	}
	int l = 0, r = n;
	while( l <= r){
		int k = (l + r)/2;
		bool check = false;
		for(int i = 1; i<=n;i++){
			for(int j = 1; j <=n;j++){
				bool first = false;
				if( i - k>=0 && i + k-1 <=n){
					if(prefixv[i+k-1][j] - prefixv[i-k][j] == 2*k-1) first = true;
				}
				bool second = false;
				if( j -k>=0 && j + k-1 <=n){
					if(prefix[i][j+k-1] - prefix[i][j-k] == 2*k-1 ) second = true;
				}
				if(first && second) check = true;
			}
		}
		if(check) l = k+1;
		else r = k-1;
	}
	return (r==-1)?0:r;
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
