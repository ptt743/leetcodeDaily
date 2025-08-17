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
int solve(){
	vector<vector<int>> fruits={{1,2,3,4},{5,6,8,7},{9,10,11,12},{13,14,15,16}};
	int n = fruits[0].size();

	int ans = 0;
	for(int i =0;i< n;i++) 
		ans+= fruits[i][i];

	function<int()> dp=[&](){
		vector<int> prev(n, INT_MIN), curr(n,INT_MIN);

		prev[n-1] = fruits[0][n-1];

		for(int i =1; i< n-1;i++){
			for(int j = max( n - i -1, i+1); j< n;j++){
				int best = prev[j];
				if(j -1>=0) best = max(best, prev[j-1]);
				if(j+1 <n) best = max( best, prev[j+1]);
				curr[j] = best + fruits[i][j];
			}
			swap(prev, curr);
		}
		return prev[n-1];
	};

	ans += dp();
	for(int i =0;i< n;i++){
		for(int j = i;j< n; j++)
			swap(fruits[i][j], fruits[j][i]);
	}
	ans += dp();
	return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout<<solve()<<endl;
    return 0;
}
