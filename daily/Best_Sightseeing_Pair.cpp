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
	vector<int> values;
	int n = values.size();

	int maxVal = values[0] + 0;
	int res = INT_MIN;
	for(int i = 1;i< n;i++){
		res = max( res, maxVal + values[i] - i);
		maxVal = max(maxVal, values[i] + i);
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
