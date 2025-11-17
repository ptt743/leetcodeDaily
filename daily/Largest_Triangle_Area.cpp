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
	function<double(vector<int>&, vector<int>&, vector<int>&)>calc =[&](vector<int>& P, vector<int>&R, vector<int>&Q){
		return 0.5 * abs(P[0]*Q[1] + R[1]*Q[0] + R[0]*P[1] - P[1]*Q[0] - R[0]*Q[1] - R[1]*P[0]) ;
	};
	double res = 0.0;
	for(int i =0;i< n;i++){
		for(int j = i+1;j<n;j++){
			for(int k = j+1;k< n;k++){
				res = max(res, calc(points[i], points[j], points[k]));
			}
		}
	}
	cout<< res <<endl;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
