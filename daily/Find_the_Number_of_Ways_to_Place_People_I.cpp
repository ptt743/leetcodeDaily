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
#include<climits>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	vector<vector<int>> points={{1,1},{2,2},{3,3}};
	
	int n = points.size();

	function<bool(vector<int>&, vector<int>&)> comp=[&]( vector<int>& a, vector<int>& b){
		return a[0] < b[0] || ( a[0] == b[0] && a[1] > b[1]);
	};
	sort(points.begin(), points.end(), comp);
	int res = 0;

	for(int i =0;i< n-1;i++){
		int x_min = points[i][0]-1;
		int y_min = INT_MIN;
		int y_max = points[i][1] +1;
		int x_max = INT_MAX;
		for(int j = i +1;j < n;j++){
			if(points[j][0] > x_min && points[j][0] < x_max && points[j][1] > y_min && points[j][1] < y_max){
				y_min = points[j][1];
				x_min = points[j][0];
				res++;
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
