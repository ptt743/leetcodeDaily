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
	vector<vector<int>> points;
	int n = points.size();
	int sum = 0;
	for(int i = 1;i<n;i++){
		int u = abs(points[i][0] - points[i-1][0]);
		int v = abs(points[i][1] - points[i-1][1]);
		if(u == v) sum+= u;
		else sum += max(u,v);
	}
	return sum;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
