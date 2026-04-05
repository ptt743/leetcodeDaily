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
	int m,n;
	vector<int> hFences;
	vector<int> vFences;
	hFences.push_back(1);
    	hFences.push_back(m);
	vFences.push_back(1);
    	vFences.push_back(n);

	sort(hFences.begin(), hFences.end());
	sort(vFences.begin(), vFences.end());

	unordered_set<long long> sth, stv;
	for(int i = 0;i< hFences.size();i++){
		for(int j = 0; j < i ;j++){
			sth.insert(hFences[i] - hFences[j]);
		}
	}
	for(int i = 0;i< vFences.size();i++){
		for(int j = 0; j < i ;j++){
			stv.insert(vFences[i] - vFences[j]);
		}
	}
	long long area = 0;
	int mod = 1e9 + 7;
	for(long long item : sth)
		if(stv.find(item)!=stv.end()){
			area = max((item*item), area);
		}
    	area%=mod;
	return (area==0)?-1:area;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
