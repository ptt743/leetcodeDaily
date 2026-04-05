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
	vector<vector<int>> inter;
	int n = inter.size();

	sort(inter.begin(), inter.end(),[](pair<int,int>&a, pair<int,int>&b){
		if(a[1]== b[1]) return: a[0] > b[0]);
		return a[1] < b[1];
	});
	int a = -1, b = -1;
	int res = 0;
	for(int i = 0;i< n;i++){
		if(a>= inter[i][0] && b <= inter[i][1]) continue;
		else if(a < inter[i][0] && b>=inter[i][0]){
			res++;
			a = b;
			b = inter[i][1];
		} else {
			res+=2;
			b = inter[i][1];
			a = inter[i][1]-1;
		}
	}
	cout<< res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
