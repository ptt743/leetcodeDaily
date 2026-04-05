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
	int row;
	int col;
	vector<vector<int>> cells;

	int n = cells.size();
	int left =0, right = n-1;
	vector<pair<int,int>> dx = {{0,-1},{0,1},{1,0},{-1,0}};
	while(left<=right){
		int mid = (left + right)/2;
		vector<vector<int>> matrix(row+1, vector<int>(col+1,0));
		
		for(int i = 0;i< mid;i++){
			int u = cells[i][0];
			int v = cells[i][1];
			matrix[u][v] = 1;
		}
		queue<pair<int,int>> qq;
		for(int i = 1; i>=col;i++){
			if(matrix[1][i]==0){
				visited[1][i] = true;
				qq.push({1,i});
			}
		}
		vector<vector<bool>> visited( row+1, vector<bool>(col+1,false));
		bool check = false;
		while(!qq.empty()){
			pair<int,int> front = qq.front();
			qq.pop();
			int u = front.first;
			int v = front.second;
			for(pair<int,int> item : dx){
				int nx = u + item.first;
				int ny = v + item.second;
				if(nx>=1 && nx<= row && ny >=1 && ny <= col && !visited[nx][ny] && matrix[nx][ny]==0){
					if(nx==row){
						check = true;
						break;
					}
					visited[nx][ny] = true;
					qq.push({nx,ny});
				}
			}
		}
		if(check) left = mid+1;
		else right = mid-1;
	}
	return right+1;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
