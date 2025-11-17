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
	vector<vector<int>> heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
	int n = heightMap.size();
	int m = heightMap[0].size();

	vector<vector<int>> volume(n, vector<int>(m,0));
	for(int i =0;i< n;i++)
		for(int j = 0;j<m;j++){
			volume[i][j] = heightMap[i][j];
		}
	bool upt = true, init = true;
	while(upt){
		upt = false;
		for(int i =1;i<n;i++)
			for(int j = 1;j< m;j++){
				int val = max(heightMap[i][j], min(volume[i-1][j], volume[i][j-1]));
				if(init || val>volume[i][j]){
					upt = true;
					volume[i][j] = val;
				}
			}
		init = false;
		for(int i = n-2;i>=0;i--){
			for(int j = m -2;j>=0;j--){
				int val = max(heightMap[i][j], min(volume[i+1][j], volume[i][j+1]));
				if(val> volume[i][j]){
					upt = true;
					volume[i][j] = val;
				}
			}
		}
	}
	int result = 0;
	for(int i =1;i< n-1;i++){
		for(int j = 1;j<m-1;j++){
			result += volume[i][j] - heightMap[i][j];
		}
	}

	cout<< result <<endl;
}

void solve2(){
	vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
	int n = heightMap.size();
	int m = heightMap[0].size();
	vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m,false));
	struct node{
		int x;
		int y;
		int h;
		node(int a, int b, int c){
			x = a;
			y = b;
			h = c;
		};
	};
	struct compare{
		bool operator()(const node& a, const node&b){
			return a.h > b.h;
		}
	};
	priority_queue<node, vector<node>, compare> pq;

	for(int i =0;i< n;i++){
		pq.push(node(i,0,heightMap[i][0]));
		pq.push(node(i,m-1, heightMap[i][m-1]));
		visited[i][0] = true;
		visited[i][m-1] = true;
	}
	for(int i= 0;i<m;i++){
		pq.push(node(0,i, heightMap[0][i]));
		pq.push(node(n-1,i,heightMap[n-1][i]));
		visited[0][i] = true;
		visited[n-1][i] = true;
	}
	vector<int> dx = {1,-1,0,0};
	vector<int> dy = {0,0,1,-1};
	int res = 0;
	while(!pq.empty()){
		node top = pq.top();
		pq.pop();
		for(int i =0;i< 4;i++){
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]) continue;
			if(heightMap[nx][ny] < top.h) res += top.h - heightMap[nx][ny];
			visited[nx][ny] = true;
			pq.push(node(nx,ny,max(heightMap[nx][ny], top.h)));
		}
	}
	cout<< res <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
