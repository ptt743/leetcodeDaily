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
	string s;
	int minJump;
	int maxJump;
	int n = s.size();

	if(s[n-1]=='1') return false;

	vector<bool> visited(n,false);
	visited[0] = true;
	queue<int> qq;
	qq.push(0);
	int maxind = 0;
	while(!qq.empty()){
		int front = qq.front();
		qq.pop();
		for(int index = max(front + minJump,maxind); index<=min(n-1, front + maxJump);index++){
			if(visited[index]== false && s[index]=='0'){
				visited[index]= true;
				qq.push(index);
				
			}
			maxind = max(maxind, front+maxJump);
		}
	}
	return visited[n-1];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
