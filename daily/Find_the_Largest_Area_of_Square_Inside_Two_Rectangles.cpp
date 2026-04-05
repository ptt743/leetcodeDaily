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
	vector<vector<int>> bottomLeft;
	vector<vector<int>> topRight;
	int n = bottomLeft.size();
	long long area = 0;
	for(int i =0;i< n;i++){
		for(int j =0;j<i;j++){
			pair<int,int> top = {min(topRight[i][0], topRight[j][0]), min(topRight[i][1], topRight[j][1])};
			pair<int,int> bottom = {max(bottomLeft[i][0], bottomLeft[j][0]), max(bottomLeft[i][1], bottomLeft[j][1])};
			if(!(top.second> bottom.second && top.first > bottom.first)){
				continue;
			}
			long long len = min((1ll*top.second - bottom.second), ( 1ll*top.first - bottom.first));
			area = max(area, len*len);
		}
	}
	return area;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
