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
	vector<int> complexi;
	int n = complexi.size();
	int minVal = INT_MAX;
	long long res = 1;
	for(int i = 1;i<n;i++){
		if(complexi[i]<= complexi[0]) return 0; 
		res*=(i>0)?i:1ll;
		res%=mod;
	}
	return res;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
