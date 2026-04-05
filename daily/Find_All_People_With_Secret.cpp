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
	vector<vector<int>> meetings;
	int first;

        struct node{
		int x;
		int y;
		int time;
	};
	vector<node> arr;
	int m = meetings.size();
	for(int i = 0;i< m;i++) arr.push_back({meetings[i][0], meetings[i][1], meetings[i][2]});
	arr.push_back({0,first,0});

	function<bool(node,node)> option = [&]( node a, node b){
		return a.time < b. time;
	};
	sort(arr.begin(), arr.end(), option);

	vector<bool> visited(n,false);
	visited[0] = true;
	visited[first] = true;

	
	int count = 0;
	
	vector<int> parent (n,-1);
	vector<int> sz(n,0);
	std::iota(parent.begin(), parent.end(), 0);
	function<int(int)> find=[&](int i) {
        	if (parent[i] == i)
            		return i;
        	return parent[i] = find(parent[i]); // Gán thẳng vào gốc
    	};

	function<void(int,int)> unite=[&](int i, int j) {
        	int root_i = find(i);
        	int root_j = find(j);
            if (root_i != root_j) {
                if (sz[root_i] < sz[root_j]) {
                    swap(root_i, root_j);
                }
                parent[root_j] = root_i;
                if(visited[root_j]) visited[root_i] = true;
                if(visited[root_i]) visited[root_j] = true;
                sz[root_i] += 1;
            }
	};
	int len = arr.size();
	int left =1;
	for(int i =1 ;i<=len;i++){
		if(i==len || arr[i].time!= arr[left].time){
			for(int j = left; j< i;j++){
				unite(arr[j].x, arr[j].y);
			}
			for(int j = left; j<i;j++){
				int rootx = find(arr[j].x);
				if(visited[rootx]) visited[arr[j].x] = true;
				if(visited[rootx]) visited[arr[j].y] = true;
			}
			for(int j = left; j<i;j++){
				int u = arr[j].x;
				int v = arr[j].y;
				parent[u]= u;
				parent[v]= v;
				sz[u] = 0;
				sz[v] = 0;
			}
		    	left = i;
		}
	}

	vector<int> res;
	for(int i = 0;i< n;i++){
		if(visited[i]){
			res.push_back(i);
		}
	}
	return res;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
