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
	int amount;
	vector<int> coins;
	int n = coins.size();

	vector<long long> dp(amount+1, 0);
	dp[0] = 1;
    	for(int item : coins){
    		for(int i = 1;i<=amount;i++){	
			if(i>=item){
				dp[i] +=dp[i-item];
                dp[i]%= INT_MAX;
			}
		}
        //cout<< i <<" "<< dp[i]<<endl;
	}
	return dp[amount];
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
