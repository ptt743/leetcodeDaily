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
 * digital dynamic programing
 * => find number of integer with given range
 *  fix suffix and find how many prefix can be combined to it to form number in certain range
 *  template : dp[index][state][ extend state]
*/

void solve(){
	long long start;
	int limit;
	string s;
	long long finish;
	
	string high = to_string(finish);
	string low = to_string(start);
	int n = high.size();
	int sizepre = n - low.size();
	low = string( n - low.size(),'0') + low;
	int dp[21][2][2]={};
	dp[0][1][1] = 0;
	for(int i =0;i< n;i++){
		for( int sl = 0;sl <2; sl++){
			for(int sh = 0; sh< 2;sh++){
				int curr = dp[i][sl][sh];
				int lo = sl? low[i] : '0';
				int hi = sh? high[i] : '9';
				if(i< lowsize){
					for(int num = lo;num<=hi;num++){
						
					}
				} else{
					
				}
			}
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
