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
	vector<int> happiness;
	int k;
	int n = happiness.size();

	sort(happiness.begin(), happiness.end());
	int count = 0;
	long long res =0;
	for(int i = n-1;i>= max(0,n - k);i--){
		res += (happiness[i]- count)>=0?( happiness[i] - count):0 ;
		count++;
	}
	return res;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
