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
	vector<int> arr;
	int start;
	int n = a.size();
	queue<int> qq;
	vector<int> visited(n,false);
	visited[start] = true;
	qq.push(start);
	while(!qq.empty()){
		int front = qq.front();
		if(a[front] ==0) return true;
		qq.pop();
		if(front - a[front]>=0 && visited[front - a[front]]==false){
			visited[front - a[front]] = true;
			qq.push(front - a[front]);
		}
		if(front + a[front]<n && visited[front + a[front]]==false){
			visited[front + a[front]] = true;
			qq.push(front + a[front]);
		}
	}
	return false;
}

 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
