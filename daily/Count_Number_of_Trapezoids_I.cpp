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
	int mod = 1e9 + 7;
	unordered_map<int,int> mp;
	for(int i = 0;i< n;i++){
		mp[points[i][1]]++;
	}
	vector<long long> temp;
	for(auto item : mp){
		if(item.second>=2){
			long long val = item.second;
			long long res = val % mod;
			res = res * ((val - 1) % mod) % mod;
			res = (res * 500000004) % mod;   // thay thế cho chia 2
			temp.push_back(res);
        }
	}

	int m = temp.size();
	long long result = 0;
	for(int i = 1;i< m;i++){
		result += ( (temp[i]%mod) * (temp[i-1]%mod))%mod;
        result%=mod;

		temp[i]+= temp[i-1];
	}
	return result;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
