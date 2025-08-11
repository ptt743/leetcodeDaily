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
	vector<vector<int>> events = {{1,3,4},{2,4,1},{1,1,4},{3,5,1},{2,5,5}};
	int k = 3;
	function<bool(vector<int>&, vector<int>&)> comp=[&](vector<int>&a, vector<int>&b){
		return a[1]< b[1] || (a[1]==b[1] && a[0]<b[0]);
	};	
	sort(events.begin(), events.end());
        int n = events.size();
        
        function<int(int)> binaryS = [&](int val)->int{
            int left = 0, right = n-1;
            while(left<= right){
                int mid = (left + right)/2;
                if(events[mid][0]> val) right = mid-1;
                else left = mid+1;
            }
            return left;
        };
        vector<vector<int>> dp (n+1, vector<int>(k+1,0));
        for(int i =0;i< n; i++){
		int index = binaryS(events[i][1]);
		for(int j = 0;j<k;j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			dp[index][j+1] = max(dp[index][j+1], dp[i][j] + events[i][2]);
		}
	}
	int ans = 0;
	for(int i =0;i<=k;i++) ans = max(ans, dp[n][i]);
        cout<<ans<<endl;		
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
