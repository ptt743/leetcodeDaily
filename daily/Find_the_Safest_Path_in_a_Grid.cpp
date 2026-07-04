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
	vector<vector<int>> grid;
	int n = grid.size();
    	if(n==1) return 0;
	vector<int> dx = {-1,1,0,0};
	vector<int> dy = {0,0,1,-1};

	int x = 0;
	int y = 0;

	vector<vector<pair<int,int>>> dist(n, vector<pair<int,int>>(n,{-1,-1}));
	queue<pair<int,int>> qq;
	for(int i = 0;i< n;i++){
		for(int j = 0;j<n;j++){
			if(grid[i][j]==1){
				qq.push({i,j});
                dist[i][j] = {i,j};
            }
                
		}
	}
	while(!qq.empty()){
		pair<int,int> front = qq.front();
		qq.pop();
		for(int i =0;i< 4;i++){
			int nx = front.first + dx[i];
			int ny = front.second + dy[i];
			if( nx >=0 && nx <n && ny >=0 && ny<n){
				if(dist[nx][ny]==make_pair(-1,-1) && grid[nx][ny]!=1){
					dist[nx][ny] = dist[front.first][front.second];
					qq.push({nx,ny});
				}
			}
		}
	}
	int left = 0, right = n;
	while(left<=right){
		int mid =(left + right)/2;
		queue<pair<int,int>> qq1;
		bool check2 = false;
		qq1.push({0,0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
		while(!qq1.empty()){
			pair<int,int> front = qq1.front();
			qq1.pop();
			if(front.first==n-1&&front.second==n-1){
				check2 = (abs(0 - dist[0][0].first) + abs(0 - dist[0][0].second))>=mid;
                break;
			}
			for(int i = 0;i< 4;i++){
				int nx = front.first + dx[i];
				int ny = front.second + dy[i];
				if(nx>=0 && nx <n && ny>=0 && ny<n  && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    int value = abs(nx - dist[nx][ny].first) + abs(ny - dist[nx][ny].second);
                    if(value>=mid){
					    qq1.push({nx,ny});
                    }
				}
			}
		}
		if(check2) left = mid +1;
		else right = mid-1;
	}
	return right;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
