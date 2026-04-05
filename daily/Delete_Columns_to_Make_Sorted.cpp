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
	vector<string> strs;
	int n = strs.size();

	int count =0;
	int len =strs[0].size();
	vector<bool> visited(len,false);
	for(int i = 1;i< n;i++){
		for(int j = 0;j<len;j++)
		if(strs[i][j]<strs[i-1][j]) visited[j] = true;
	}
	for(int j = 0;j< len;j++)
		if(visited[j]) count++;
	return count;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
