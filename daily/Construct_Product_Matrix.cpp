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
	vector<vector<int>> grid;
	int n = grid.size();
	int m = grid[0].size();
	long long product = 1ll;
	int mod = 12345;
	vector<pair<int,int>> p;
	int t=0;
	for(int i =0;i< n;i++){
		for(int j =0;j<m;j++){

			p.push_back({t++, grid[i][j]});
		}
	}
	vector<long long> suffix(n*m,1);
	for(int i = n*m-2;i>=0;i--){
		suffix[i] = p[i+1].second* suffix[i+1]%mod;
	}
	
	vector<long long >prefix(n*m,1);
	for(int i =1;i< n*m;i++){
		prefix[i]= prefix[i-1] * p[i-1].second %mod;
		
	}
	vector<vector<int>> res(n, vector<int>(m,1));
	int count =0;
	for(int i = 0;i< n;i++){
		for(int j = 0;j<m;j++){
			res[i][j]= suffix[count] * prefix[count] %mod; 
            count++;
		}
	}
	return res;	

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
