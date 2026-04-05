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
	vector<vector<int>> matrix;
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> dp(m,0);
	int res = 0;
	for(int i = 0;i< n;i++){
		for(int j = 0;j<m;j++){
			if(matrix[i][j]=='1') dp[j] +=1;
			else dp[j] =0;
        	}
        	vector<int> prefix(m,0);
        	stack<int> stl;
		for(int j = 0;j<m;j++){
			while(!stl.empty() && dp[stl.top()] >= dp[j]) stl.pop();
			int left = ( stl.empty())?-1: stl.top();
			prefix[j] = left+1;
            		stl.push(j);
		}
        
        	stack<int> str;
        	vector<int> suffix(m,0);
		for(int j = m-1;j>=0;j--){
			while(!str.empty() && dp[str.top()] >= dp[j]) str.pop();
			int right = ( str.empty())?m: str.top();
			suffix[j] = right;
            		str.push(j);
		}

        	for(int j=0;j<m;j++) 
			res = max(res, dp[j]*(suffix[j] - prefix[j]));
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
