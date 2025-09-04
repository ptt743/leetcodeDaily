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
	vector<pair<int,int>> data;
	int n = points.size();
	for(int i =0;i< n;i++){
		data.push_back({points[i][0], points[i][1]});
	}
	sort( data.begin(), data.end());

	for(int i =0;i< n;i++){
		
	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
