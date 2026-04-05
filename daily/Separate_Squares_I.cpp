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
	vector<vector<int>> squares;
	int n = squares.size();
	double sum = 0;
	double high = 0, low = 2e9;
	for(int i =0;i< n;i++){
		double edge = squares[i][2];
		low = min(low, (double)squares[i][1]);
		high = max(high, (double)squares[i][1] + edge);
		sum += edge* edge;
	}
	double target = sum/2.0;
 	for(int j =0;j< 100;j++){
		double mid = low + (high - low)/2.0;
		double current =0;
		for(int i =0;i< n;i++){
            double y = (double)squares[i][1];
		    double len = (double)squares[i][2];
			if(mid >= y){
				current +=(min(mid, y +len)  - y)*len;
			}
		}
		if(current >= target){
			high = mid;
		}else low = mid;
	}
	return high;	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
