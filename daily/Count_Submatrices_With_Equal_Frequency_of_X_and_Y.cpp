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
	vector<vector<char>> grid;

	int n = grid.size();
	int m = grid[0].size();

	vector<pair<int,int>> col(m,{0,0});
	int count = 0;
	for(int i = 0;i< n;i++){
		pair<int,int> temp = {0,0};
		for(int j = 0;j< m;j++){
			if(grid[i][j]=='X') col[j].first++;
			if(grid[i][j]=='Y') col[j].second++;
			temp.first += col[j].first;
			temp.second += col[j].second;
			if(temp.first >0 && temp.first == temp.second) count++;
		}
	}
	return count;
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
