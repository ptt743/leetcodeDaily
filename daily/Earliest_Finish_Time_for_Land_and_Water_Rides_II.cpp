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
	vector<int> a;
	vector<int> at;
	vector<int> b;
	vector<int> bt;
	function<long long(vector<int>&, vector<int>&, vector<int>&, vector<int>&)> cacul = [&](vector<int>& c, vector<int>& ct, vector<int>& d, vector<int>& dt){
		long long finish1 = LLONG_MAX;
		for(int i = 0 ;i< c.size();i++){
			finish1 = min(finish1, (long long)c[i] + ct[i]);
		}
		long long finish2 = LLONG_MAX;
		for(int i =0; i< d.size();i++){
			finish2 = min((long long)max((long long)d[i], finish1)+ dt[i], finish2);
		}
		return finish2;
	};
	return min(cacul(a,at,b,bt), cacul(b,bt,a,at));
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
