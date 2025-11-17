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
	int m=3;
	int n=3;
	vector<vector<int>> guards={{1,1}};
	vector<vector<int>> walls= {{0,1},{1,0},{2,1},{1,2}};

	vector<vector<int>> check(m, vector<int>(n,0));
	for(int i = 0;i< guards.size();i++){
		int u= guards[i][0];
		int v = guards[i][1];
		check[u][v] = 1;
	}
	
	
	for(int i = 0; i < walls.size();i++){
		int u= walls[i][0];
		int v = walls[i][1];
		check[u][v] = -1;
	}
	vector<int> rowtemp = vector<int>(m,0);
	vector<int> coltemp = vector<int>(n,0);

	for(int i = 0;i< m;i++){
		for(int j = 0;j<n;j++){
			if(check[i][j]==1){
				rowtemp[i] =1;
				coltemp[j] = 1;
				continue;
			}
			if(check[i][j]==-1){
				rowtemp[i] = 0 ;
				coltemp[j] = 0;
				continue;
			}
			if(rowtemp[i] || coltemp[j])
				check[i][j] = 2;
		} 
	}

	rowtemp = vector<int>(m,0);
	coltemp = vector<int>(n,0);

	for(int i = m-1;i>=0;i--){
		for(int j = n-1;j>=0;j--){
			if(check[i][j]==1){
				rowtemp[i] =1;
				coltemp[j] = 1;
				continue;
			}
			if(check[i][j]==-1){
				rowtemp[i] = 0 ;
				coltemp[j] = 0;
				continue;
			}
			if(rowtemp[i] || coltemp[j])
				check[i][j] = 2;
		}
	}
	int count = 0;
	for(int i = 0;i<m;i++){
		for(int j = 0; j < n;j++){
			if(check[i][j]==0) count++;
		}
	}
	cout<< count <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
