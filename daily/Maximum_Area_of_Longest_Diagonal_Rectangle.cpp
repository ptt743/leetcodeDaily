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
	vector<vector<int>> dimen;
	long long area = 0;
	long long disg = 0;
	for(int i =0;i< n;i++){
		long long a = dimen[i][0];
		long long b = dimen[i][1];
		if((a*a + b*b) >= disg){
			if((a*a + b*b > disg)) area = a*b;
			if((a*a + b*b) == disg && a*b > area) area = a*b;
			disg = a*a + b*b;
		}
	}
	return area;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
