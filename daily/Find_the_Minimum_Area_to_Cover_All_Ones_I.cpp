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
	vector<vector<int>> grid={{0,1,0},{1,0,1}};
	int n = grid.size();
	int m = grid[0].size();

	int up=0, down = 0, left =0, right = 0;

	for(int i =0;i<n;i++){
		int sum = 0;
		for(int j =0;j< m;j++){
			sum+= grid[i][j];
		}
		if(sum==0) up++;
		else break;
	}
	for(int i =n-1;i>=0;i--){
		int sum = 0;
		for(int j =0;j< m;j++){
			sum+= grid[i][j];
		}
		if(sum==0) down++;
		else break;
	}
	for(int j =0; j<m;j++){
		int sum = 0;
		for(int i =0;i< n;i++){
			sum+= grid[i][j];
		}
		if(sum==0) left++;
		else break;
	}

	for(int j =m-1;j>=0;j--){
		int sum = 0;
		for(int i =0;i< n;i++){
			sum+= grid[i][j];
		}
		if(sum==0) right++;
		else break;
	}
	cout<< (n - (up + down))* (m - (left + right))<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
